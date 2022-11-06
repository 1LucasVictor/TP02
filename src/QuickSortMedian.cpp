#include "QuickSorts.hpp"
void partitionM(int *v, int begin, int end, int &i, int &j, int &comp,
                int &atrib) {
  int pivot = v[(begin + end) / 2];
  int aux;
  atrib++;
  // Getting the median value as pivot
  if ((v[begin] > pivot && v[end] > v[begin]) ||
      (v[begin] < pivot && v[begin] > v[end])) {
    pivot = v[begin];
    comp += 4;
    atrib++;
  } else if ((v[end] > pivot && v[begin] > v[end]) ||
             (v[end] < pivot && v[end] > v[begin])) {
    pivot = v[end];
    comp += 4;
    atrib++;
  }

  i = begin;
  j = end;
  while (i <= j) {
    while (v[i] < pivot) {
      i++;
      comp++;
    }
    while (v[j] > pivot) {
      j--;
      comp++;
    }
    if (i <= j) {
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
      atrib+=3;
    }
  }
}
void quickSortM(int *v, int begin, int end, int &comp, int &atrib) {
  int i, j;
  if (begin < end) {
    partitionM(v, begin, end, i, j, comp, atrib);
    quickSortM(v, begin, j, comp, atrib);
    quickSortM(v, i, end, comp, atrib);
  }
}