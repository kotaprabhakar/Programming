#include <iostream>
using namespace std;

struct mas{
  int *x;
  char *y;
};

int main() {
  int *x;
  char *y;
  int p = 5;
  char q = '3';
  x = &p, y = &q;
  struct mas m = {x, y};
  
  return 0;
}