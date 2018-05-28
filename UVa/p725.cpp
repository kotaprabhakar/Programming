#include <algorithm>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

map<int, vector<string>> answerMap;

void swap(char *arr, int i, int index) {
  char temp;
  temp = arr[index];
  arr[index] = arr[i];
  arr[i] = temp;
}

void permute(char *arr, int index) {
  int i = 0;
  if (index == strlen(arr)) {
    char num[6], denom[6];
    memcpy(num, &arr[0], 5);
    memcpy(denom, &arr[5], 5);
    num[5] = '\0', denom[5] = '\0';
    unsigned int numi = atoi(num), denomi = atoi(denom);
    if (numi > denomi && numi % denomi == 0 &&
        !(num[0] == '0' && denom[0] == '0')) {
      if ((answerMap.find(numi / denomi)) != answerMap.end()) {
        answerMap.find(numi / denomi)->second.push_back(string(arr));
        sort(answerMap.find(numi / denomi)->second.begin(),
             answerMap.find(numi / denomi)->second.end());
      } else {
        vector<string> ex;
        ex.push_back(string(arr));
        pair<int, vector<string>> exV;
        exV.first = numi / denomi;
        exV.second = ex;
        answerMap.insert(exV);
      }
    }
    return;
  }
  for (i = index; i < strlen(arr); i++) {
    swap(arr, i, index);
    permute(arr, index + 1);
    swap(arr, i, index);
  }
}

int main() {
  char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
  permute(arr, 0);
  int i = 0;

  scanf("%d", &i);
  while (i != 0) {
    if (answerMap.find(i) == answerMap.end()) {
      printf("There are no solutions for %d.\n", i);
    } else {
      for (auto iter : answerMap.find(i)->second) {
        printf("%s / %s = %d\n", iter.substr(0, 5).c_str(),
               iter.substr(5, 5).c_str(), i);
      }
    }
    scanf("%d", &i);
    if (i != 0)
      printf("\n");
  }
  return 0;
}