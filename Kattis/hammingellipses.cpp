#include <iostream>
using namespace std;

#define MAX_SIZE 100

typedef unsigned long long longest;
longest pascaltriangle[MAX_SIZE + 1][MAX_SIZE + 1];

char *XORDecimal(char f1[], char f2[], longest n) {
  longest i;
  char *res = new char[n];
  for (i = 0; i < n; i++) {
    if (f1[i] == f2[i]) {
      res[i] = '0';
    } else {
      res[i] = '1';
    }
  }
  return res;
}

longest numOnes(char *res, longest n) {
  longest i = 0, c = 0;
  for (i = 0; i < n; i++) {
    if (res[i] == '1')
      c++;
  }
  return c;
}

void createPascalTriangle() {
  int i, j;
  pascaltriangle[0][0] = 1;
  for (i = 1; i < MAX_SIZE; i++) {
    pascaltriangle[i][0] = 1;
    for (j = 1; j <= i; j++) {
      pascaltriangle[i][j] =
          pascaltriangle[i - 1][j - 1] + pascaltriangle[i - 1][j];
    }
  }
}

longest C(longest n, longest r) { return pascaltriangle[n][r]; }

longest pow(longest x, longest y) {
  if (y == 1)
    return x;
  if (x == 0)
    return 0;
  if (y == 0)
    return 1;
  longest mid = pow(x, y / 2);
  if (y % 2 == 0) {
    return mid * mid;
  } else
    return mid * mid * x;
}

longest numPoints(char *res, longest q, longest n, longest D) {
  longest o = numOnes(res, n), k = n - o, i = 0, x = 0,
          zmin = 2 * n - D <= n - 1 ? 2 * n - D : n - 1;
  if (o == 0) {
    if (D % 2 == 0)
      return C(n, D / 2) * pow(q - 1, D / 2);
    else
      return 0;
  }

  longest outp = 0;

  for (i = 0; i <= zmin; i++) {
    if (k == 0 && D >= i + n) {
      outp += C(n, i) * C(n - i, D - i - n) * pow(q - 2, D - i - n);
      continue;
    }
    longest min = (n >= i + k) ? 0 : (i + k - n), max = i <= k ? i : k;
    for (x = min; x <= max; x++) {
      if (2 * x + D >= n + k)
        outp += C(k, x) * C(n - k, i - x) *
                C(n - k - i + x, 2 * x + D - n - k) * pow(q - 1, k - x) *
                pow(q - 2, 2 * x + D - n - k);
    }
  }
  return outp;
}

int main() {
  createPascalTriangle();
  longest q, n, D;
  char f1[MAX_SIZE + 1], f2[MAX_SIZE + 1];
  scanf("%llu %llu %llu", &q, &n, &D);
  scanf("%s", f1);
  scanf("%s", f2);
  if (D < n) {
    printf("%d\n", 0);
    return 0;
  }
  char *res = XORDecimal(f1, f2, n);
  printf("%lld\n", numPoints(res, q, n, D));
  delete[] res;
  return 0;
}