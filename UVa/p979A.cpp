#include <iostream>
using namespace std;

int main() {
  unsigned long long inp;
  scanf("%llu", &inp);
  if (inp == 0)
    printf("0");
  else if ((++inp) % 2 == 0)
    printf("%llu", inp / 2);
  else
    printf("%llu", inp);
  return 0;
}