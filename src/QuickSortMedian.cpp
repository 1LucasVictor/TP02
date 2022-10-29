#include "QuickSorts.hpp"
int partitionM(int *v, int begin, int end) {
  int pivotInd = (begin + end) / 2;
  int aux;

  // Getting the median value as pivot
  if (v[begin] > v[pivotInd]) {
    aux = v[begin];
    v[begin] = v[pivotInd];
    v[pivotInd] = aux;
  }
  if (v[end] > v[pivotInd]) {
    aux = v[end];
    v[end] = v[pivotInd];
    v[pivotInd] = aux;
  }

  int i = begin, j = end;
  while (i < j) {
    while (v[i] < v[pivotInd])
      i++;
    while (v[j] > v[pivotInd])
      j--;
    if (i < j) {
      if (pivotInd == i)
        pivotInd = j;
      else if (pivotInd == j)
        pivotInd = i;
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }
  }
  return pivotInd;
}
void quickSortM(int *v, int begin, int end) {
  if (begin < end) {
    int pivotInd = partitionM(v, begin, end);
    quickSortM(v, begin, pivotInd - 1);
    quickSortM(v, pivotInd + 1, end);
  }
}