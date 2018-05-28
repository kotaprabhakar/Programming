#include <iostream>
using namespace std;

int main() {
  char c;
  bool e = true;
  do {
    c = getchar();
    if (c == '\"') {
      e = e ? false : true;
      if (!e) {
        putchar('`');
        putchar('`');
      } else {
        putchar('\'');
        putchar('\'');
      }
    } else {
      putchar(c);
    }
  } while (c != EOF);
  return 0;
}