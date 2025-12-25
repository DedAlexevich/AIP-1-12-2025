#include <cassert>
#include <iostream>
#include <cctype>

void hi()
{
  std::cout << "<Hi>\n";
}

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

  if (isSkip) {
    is >> std::skipws;
  }

  return is;
}
bool is_space(char t)
{
  return std::isspace(t);
}

size_t match(const char* word, const char* const * words, size_t k)
{
  for (size_t i = 0; i < k; i++) {
    if (std::strcmp(word, words[i]) == 0) {
      return i;
    }
  }
  return k;
}

int main()
{
  size_t k = 255;
  void(*cmds[1])() = {hi};
  const char* const cmd_text = { "hi" };
  char comm[256] = {};
  constexpr size_t COUNT_COMMAND = 1;

  while (!getWord(std::cin, comm, k, is_space).eof()) {
    if (std::cin.fail()) {
      std::cerr << "INVALID INPUT\n";
      //Propusk vvoda
      return 1;
    } else if (size_t i = match(comm, &cmd_text, COUNT_COMMAND) < COUNT_COMMAND) {
      cmds[i]();
    } else {
      std::cerr << "INKNOWN COM\n";
    }

  }
}