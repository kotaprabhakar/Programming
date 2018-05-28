#include <algorithm>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>
using namespace std;

double dist(int x1, int y1, int x2, int y2, int prevMax);

class pair_pt {
private:
  int x, y;

public:
  void set_coord(int x, int y) {
    this->x = x;
    this->y = y;
  };
  int get_x() { return x; }
  int get_y() { return y; }
};

bool comparator(pair_pt *a, pair_pt *b) { return (a->get_x() < b->get_x()); }

int main() {
  int C;
  scanf("%d", &C);
  while (C--) {
    int N, i = 0, prevMax = 0, x, y;
    double summ = 0;
    scanf("%d", &N);
    vector<pair_pt *> points;
    do {
      scanf("%d %d", &x, &y);
      points.push_back(new pair_pt());
      points[i]->set_coord(x, y);
    } while (i++ != N - 1);
    sort(points.begin(), points.end(), comparator);
    i = 0;
    while (N--) {
      if (N != 0 && points[N]->get_y() < points[N - 1]->get_y() &&
          points[N - 1]->get_y() > prevMax) {
        summ = summ + dist(points[N - 1]->get_x(), points[N - 1]->get_y(),
                           points[N]->get_x(), points[N]->get_y(), prevMax);
        prevMax = points[N - 1]->get_y();
      }
    }
    printf("%f\n", summ);
    for (auto iter = points.begin(); iter != points.end(); ++iter) {
      delete *iter;
    }
  }
  return 0;
}

double dist(int x1, int y1, int x2, int y2, int prevMax) {
  return ((y1 >= prevMax) ? (y1 - prevMax) : (prevMax - y1)) *
         sqrt(1 + (x2 - x1) * (x2 - x1) / ((y2 - y1) * (y2 - y1)));
}