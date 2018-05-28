#include <iostream>
using namespace std;

int main() {
  int n, i = 0;
  unique_ptr<int[]> w;
  char *s;

  scanf("%d", &n);
  w = make_unique<int[]>(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  scanf("%s", s);

  

  return 0;
}