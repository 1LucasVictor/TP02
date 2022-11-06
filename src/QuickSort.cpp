#include "QuickSorts.hpp"
void partition(int *v, int begin, int end, int &i, int &j, int &comp, int &atrib) {
  int pivot = v[(begin + end) / 2];
  atrib++;
  i = begin; j = end;
  int aux;
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
void quickSort(int *v, int begin, int end, int &comp, int &atrib) {
  int i, j;
  if (begin < end) {
    partition(v, begin, end, i, j, comp, atrib);
    quickSort(v, begin, j, comp, atrib);
    quickSort(v, i, end, comp, atrib);
  }
}