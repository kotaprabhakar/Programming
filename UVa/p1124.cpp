#include <iostream>
using namespace std;

int main() {
  char c;
  do {
    c = getchar();
    putchar(c);
  } while (c != EOF);
  return 0;
}