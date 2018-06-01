#include <cmath>
#include <iostream>
using namespace std;

double least(int x[], int y[], int c1) {
  int i = 0, j = 0;
  double opt = -1.0;
  if (c1 == 2) {
    return sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
  }
  for (i = 1; i < c1; i++) {
    const int c2 = c1 - 2;
    int x1[c2], y1[c2], k = 0;
    double t = 0, d = sqrt((y[i] - y[0]) * (y[i] - y[0]) +
                           (x[i] - x[0]) * (x[i] - x[0]));
    for (j = 0; j < c1; j++) {
      if (j != i && j != 0) {
        x1[k] = x[j];
        y1[k++] = y[j];
      }
    }
    t = least(x1, y1, c2);
    if (opt == -1.0) {
      opt = d + t;
    } else if (opt >= d + t) {
      opt = d + t;
    }
  }
  return opt;
}

int main() {
  int c, p, ca = 0;
  scanf("%d", &c);
  ca++;
  while (c != 0) {
    const int c1 = 2 * c;
    int i, x[c1], y[c1];
    double opt = 0;
    char name[20];
    for (i = 0; i < c1; i++)
      scanf("%s %d %d", name, x + i, y + i);
    opt = least(x, y, c1);
    printf("Case %d: %.2f\n", ca++, opt);
    scanf("%d", &c);
  }
}