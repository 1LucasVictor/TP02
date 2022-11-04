#include <iostream>

#include "QuickSorts.hpp"
using namespace std;
#define len 500
void printVector(int *v, int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << ", ";
  }
  cout << endl;
}
int main() {
  int v[len];
  for (int i = 0; i < len; i++) {
    v[i] = rand() % 30;
  }
  QuickSortNR(v, len);
  printVector(v, len);
  return 0;
}