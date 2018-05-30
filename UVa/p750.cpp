#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int board_size = 8;

void putQueen(int (*board)[board_size], int i, int j) { board[i][j] = 1; }

void removeQueen(int (*board)[board_size], int i, int j) { board[i][j] = 0; }

bool isValidCoord(int (*board)[board_size], int i, int j) {
  int k = 0, l = 0;
  for (k = 0; k < board_size; k++)
    if (board[k][j])
      return false;
  for (l = 0; l < board_size; l++)
    if (board[i][l])
      return false;
  for (k = i, l = j; k < board_size && l < board_size; k++, l++)
    if (board[k][l])
      return false;
  for (k = i, l = j; k >= 0 && l >= 0; k--, l--)
    if (board[k][l])
      return false;
  for (k = i, l = j; k < board_size && l >= 0; k++, l--)
    if (board[k][l])
      return false;
  for (k = i, l = j; k >= 0 && l < board_size; k--, l++)
    if (board[k][l])
      return false;
  return true;
}

int getEmptyRow(int (*board)[board_size]) {
  int i = 0, j = 0, c = 0;
  for (; i < board_size; i++) {
    for (j = 0, c = 0; j < board_size; j++)
      if (board[i][j] == 0)
        c++;
    if (c == board_size)
      return i;
  }
  return -1;
}

void backtrack(int (*board)[board_size], vector<string> &res) {
  int i = 0, j = 0, c = 0;
  i = getEmptyRow(board);
  if (i == -1) {
    int row, col;
    char arr[board_size + 1];
    for (row = 0; row < board_size; row++) {
      for (col = 0; col < board_size; col++) {
        if (board[row][col] == 1) {
          arr[col] = 48 + row + 1;
          break;
        }
      }
    }
    arr[board_size] = '\0';
    res.push_back((string)arr);
    return;
  }
  for (j = 0; j < board_size; j++) {
    if (isValidCoord(board, i, j)) {
      putQueen(board, i, j);
      backtrack(board, res);
      removeQueen(board, i, j);
    }
  }
}

int main() {
  int board[board_size][board_size] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0}},
      N, x, y, i;
  scanf("%d", &N);
  while (N--) {
    i = 1;
    vector<string> res;
    scanf("%d %d", &x, &y);
    board[x - 1][y - 1] = 1;
    backtrack(board, res);
    sort(res.begin(), res.end());
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n");
    printf("\n");
    for (auto iter : res) {
      if (i / 10 == 0)
        printf(" %d      %c %c %c %c %c %c %c %c\n", i++, iter[0], iter[1],
               iter[2], iter[3], iter[4], iter[5], iter[6], iter[7]);
      else
        printf("%d      %c %c %c %c %c %c %c %c\n", i++, iter[0], iter[1],
               iter[2], iter[3], iter[4], iter[5], iter[6], iter[7]);
    }
    board[x - 1][y - 1] = 0;
    if (N != 0)
      printf("\n");
  }
  return 0;
}