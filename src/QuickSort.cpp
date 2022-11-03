#include "QuickSorts.hpp"
void partition(int *v, int begin, int end, int &i, int &j) {
  int pivot = v[(begin + end) / 2];
  i = begin; j = end;
  int aux;
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
void quickSort(int *v, int begin, int end) {
  int i, j;
  if (begin < end) {
    partition(v, begin, end, i, j);
    quickSort(v, begin, j);
    quickSort(v, i, end);
  }
}