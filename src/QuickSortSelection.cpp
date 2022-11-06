#include "QuickSorts.hpp"
void selection(int *v, int begin, int end, int &comp, int &atrib) {
  int aux;
  for (int i = end; i > begin; i--) {
    int biggest = 0;
    for (int j = begin; j <= i; j++) {
      if (v[j] > v[biggest]) biggest = j;
      comp++;
    }
    aux = v[i];
    v[i] = v[biggest];
    v[biggest] = aux;
    atrib += 3;
  }
}
void partitionS(int *v, int begin, int end, int &i, int &j, int &comp,
                int &atrib) {
  int pivot = v[(begin + end) / 2];
  atrib++;
  i = begin;
  j = end;
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
      atrib += 3;
    }
  }
}
void quickSortS(int *v, int begin, int end, int &comp, int &atrib) {
  int i, j;
  if ((end - begin + 1) <= 100) {
    selection(v, begin, end, comp, atrib);
  } else if (begin < end) {
    partitionS(v, begin, end, i, j, comp, atrib);
    quickSortS(v, begin, j, comp, atrib);
    quickSortS(v, i, end, comp, atrib);
  }
}
