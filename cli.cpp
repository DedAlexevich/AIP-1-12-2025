#include <cassert>
#include <iostream>
#include <cctype>
#include <cstring>
#include <limits>

void skipLine(std::istream& is)
{
  using lim_t = std::numeric_limits< std::streamsize >;
  is.ignore(lim_t::max(), '\n');
}

void next(std::ostream& os, std::istream& is, size_t& context)
{
  size_t i = 0;

  if (!(is >> i)) {
    throw std::logic_error("EROR\n");
  }
  context = i;
  skipLine(is);
  os << "<OK/>\n";
}


void last(std::ostream& os, std::istream& is, size_t& context)
{
  os << "<last: "<< context <<"/>\n";
  skipLine(is);
}

struct cmd {
  virtual const char* name() = 0;
  virtual const char* help() = 0;
  virtual const char* desc() = 0;
  virtual void invoke() = 0;
};

std::istream& getWord(std::istream& is, char* word, size_t k, bool(*c)(char))
{
  assert(k > 0 && "k must be greater then zero");
  if (k <= 0 || !word) {
    throw std::logic_error("INVALID, BAD buffer size");
  }
  bool isSkip = is.flags() & std::ios::skipws;
  is >> std::noskipws;
  size_t i = 0;
  for (char t; is && !c(t) && (i < k-1); ++i) {
    is >> t;
    word[i] = t;
  }
  if (i == k) {
    is.clear(is.rdstate() | std::ios::failbit);
  }
  word[i-1] = 0;
  if (isSkip) {
    is >> std::skipws;
  }
  return is;
}
bool is_space(char t)
{
  return std::isspace(t);
}

size_t match(const char* word, const char* const* words, size_t k)
{
  for (size_t i = 0; i < k; i++) {
    size_t l1 = std::strlen(word);
    const char* s2 = words[i];
    size_t l2 = std::strlen(s2);
    bool f = l1 == l2;
    f = f && (std::strcmp(word, words[i]) == 0);
    if (f) {
      return i;
    }
  }
  return k;
}

int main()
{
  size_t k = 255;
  using cmd_t = void(*)(std::ostream&, std::istream&, size_t&);
  cmd_t cmds[] = {next, last};
  const char* const cmd_text[2] = { "next", "last"};
  char comm[256] = {};
  constexpr size_t COUNT_COMMAND = 2;
  size_t context = 0;

  while (!getWord(std::cin, comm, k, is_space).eof()) {
    if (std::cin.fail()) {
      std::cerr << "INVALID INPUT\n";
      //Propusk vvoda
      return 1;
    } else {
      if (size_t i = match(comm, cmd_text, COUNT_COMMAND); i < COUNT_COMMAND) {
        try {
          cmds[i](std::cout, std::cin, context);
        } catch (std::exception& e) {
          std::cerr << e.what();
          if (std::cin.fail()) {
            std::cin.clear(std::cin.rdstate() & ~std::ios::failbit);
          }
          skipLine(std::cin);
        }
      } else {
        std::cerr << "INKNOWN COM\n";
      }
    }
  }
}