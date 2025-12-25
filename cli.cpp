#include <iostream>

void hi()
{
  std::cout << "<Hi>\n";
}
int main()
{
  size_t i = 0;
  void(*cmds[1])() = {hi};
  constexpr size_t COUNT_COMMAND = 1;

  while (!(std::cin >> i).eof()) {
    if (std::cin.fail()) {
      std::cerr << "INVALID INPUT\n";
      //Propusk vvoda

      return 1;
    } else if (i < COUNT_COMMAND) {
      cmds[i]();
    } else {
      std::cerr << "INKNOWN COM\n";
    }

  }
}