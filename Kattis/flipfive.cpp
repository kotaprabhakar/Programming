#include <iostream>
#include <string.h>
using namespace std;

const int board_dim = 3;
const int board_size = board_dim * board_dim;

void flipBit(char white[], int i) {
  if (white[i] == '0')
    white[i] = '1';
  else
    white[i] = '0';
}

void flipFive(char white[], int i) {
  int m = i / board_dim, n = i % board_dim;
  flipBit(white, i);
  if ((m - 1) >= 0)
    flipBit(white, (m - 1) * board_dim + n);
  if ((m + 1) < board_dim)
    flipBit(white, (m + 1) * board_dim + n);
  if ((n - 1) >= 0)
    flipBit(white, m * board_dim + n - 1);
  if ((n + 1) < board_dim)
    flipBit(white, m * board_dim + n + 1);
}

bool combination(char white[], char board[], char indicator[], int r) {
  if (r == 0) {
    if (strcmp(white, board) == 0)
      return true;
    else
      return false;
  }
  bool x = false;
  for (int i = 0; i < board_size; i++) {
    if (indicator[i] == '0') {
      flipFive(white, i);
      indicator[i] = '1';
      x = x || combination(white, board, indicator, r - 1);
      flipFive(white, i);
      indicator[i] = '0';
    }
  }
  return x;
}

int main() {
  int t = 0, i = 0, j = 0;
  scanf("%d", &t);
  getchar();
  while (t--) {
    char board[board_size + 1];
    for (i = 0; i < board_dim; i++) {
      for (j = 0; j < board_dim; j++) {
        board[i * board_dim + j] = getchar();
        if (board[i * board_dim + j] == '.')
          board[i * board_dim + j] = '0';
        else
          board[i * board_dim + j] = '1';
      }
      getchar();
    }
    board[board_size] = '\0';
    if (strcmp("000000000", board) == 0) {
      printf("%d\n", 0);
      continue;
    }
    for (int i = 1; i <= board_size; i++) {
      char white[] = "000000000", indicator[] = "000000000";
      if (combination(white, board, indicator, i)) {
        printf("%d\n", i);
        break;
      }
    }
  }
}