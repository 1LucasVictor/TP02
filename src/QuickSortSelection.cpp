#include "QuickSorts.hpp"
void selection(int *v, int begin, int end) {
  int aux;
  for (int i = end; i > begin; i--) {
    int biggest = 0;
    for (int j = begin; j <= i; j++) {
      if (v[j] > v[biggest])
        biggest = j;
    }
    aux = v[i];
    v[i] = v[biggest];
    v[biggest] = aux;
  }
}
void partitionS(int *v, int begin, int end, int &i, int &j) {
  int pivot = v[(begin + end) / 2];
  i = begin;
  j = end;
  int aux;
  while (i <= j) {
    while (v[i] < pivot)
      i++;
    while (v[j] > pivot)
      j--;
    if (i <= j) {
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  }
}
void quickSortS(int *v, int begin, int end) {
  int i, j;
  if ((end - begin + 1) <= 10) {
    selection(v, begin, end);
  } else if (begin < end) {
    partitionS(v, begin, end, i, j);
    quickSortS(v, begin, j);
    quickSortS(v, i, end);
  }
}
