#include <iostream>
using namespace std;

int main() {
  int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int c[3] = {2, 6, 5};
  int(*d)[3] = &c;
  int(*a)[3] = b;
  printf("%x %x\n", *(b + 1), (b + 1)[0][0]);

  return 0;
}