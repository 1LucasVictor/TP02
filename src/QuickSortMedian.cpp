#include "QuickSorts.hpp"
void partitionM(int *v, int begin, int end, int &i, int &j) {
  int pivot = v[(begin + end) / 2];
  int aux;

  // Getting the median value as pivot
  if ((v[begin] > pivot && v[end] > v[begin]) ||
      (v[begin] < pivot && v[begin] > v[end])) {
    pivot = v[begin];
  } else if ((v[end] > pivot && v[begin] > v[end]) ||
             (v[end] < pivot && v[end] > v[begin])) {
    pivot = v[end];
  }

  i = begin; j = end;
  while (i <= j) {
    while (v[i] < pivot) i++;
    while (v[j] > pivot) j--;
    if (i <= j) {
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  }
}
void quickSortM(int *v, int begin, int end) {
  int i, j;
  if (begin < end) {
    partitionM(v, begin, end, i, j);
    quickSortM(v, begin, j);
    quickSortM(v, i, end);
  }
}