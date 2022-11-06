#include "QuickSorts.hpp"
void partitionM(Register v[], int begin, int end, int &i, int &j, int &comp,
                int &atrib) {
  auto pivot = v[(begin + end) / 2];
  Register aux;
  atrib++;
  // Getting the median value as pivot
  if ((v[begin].key > pivot.key && v[end].key > v[begin].key) ||
      (v[begin].key < pivot.key && v[begin].key > v[end].key)) {
    pivot = v[begin];
    comp += 4;
    atrib++;
  } else if ((v[end].key > pivot.key && v[begin].key > v[end].key) ||
             (v[end].key < pivot.key && v[end].key > v[begin].key)) {
    pivot = v[end];
    comp += 4;
    atrib++;
  }

  i = begin;
  j = end;
  while (i <= j) {
    while (v[i].key < pivot.key) {
      i++;
      comp++;
    }
    while (v[j].key > pivot.key) {
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
void quickSortM(Register v[], int begin, int end, int &comp, int &atrib) {
  int i, j;
  if (begin < end) {
    partitionM(v, begin, end, i, j, comp, atrib);
    quickSortM(v, begin, j, comp, atrib);
    quickSortM(v, i, end, comp, atrib);
  }
}