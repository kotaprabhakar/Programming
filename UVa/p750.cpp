#include <iostream>
using namespace std;

const int board_size = 8;
int cnt = 0;

void putQueen(char (*board)[board_size], int i, int j) { board[i][j] = 1; }

void removeQueen(char (*board)[board_size], int i, int j) { board[i][j] = 0; }

bool isValidCoord(char (*board)[board_size], int i, int j) {
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

void backtrack(char (*board)[board_size]) {
  int i = 0, c = 0;
  for (i = 0; i < board_size * board_size; i++) {
    if (isValidCoord(board, i / board_size, i % board_size)) {
      c++;
      putQueen(board, i / board_size, i % board_size);
      backtrack(board);
      removeQueen(board, i / board_size, i % board_size);
    }
  }
  if (c == 0)
    cnt++;
}

int main() {
  char board[board_size][board_size] = {
      {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  board[0][0] = 1;
  backtrack(board);
  printf("%d\n", cnt);
  return 0;
}