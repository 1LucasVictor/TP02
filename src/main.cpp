#include <iostream>

#include "QuickSorts.hpp"
using namespace std;
#define len 200000
void printVector(int *v, int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << ", ";
  }
  cout << endl;
}
int main() {
  int v[len];
  for (int i = 0; i < len; i++) {
    v[i] = rand() % 500;
  }

  int comp = 0, atrib = 0;
  quickSortS(v, 0, len-1, comp, atrib);
  printVector(v, len);
  cout << "Comparações: " << comp << "; Atribuições: " << atrib << endl;
  return 0;
}