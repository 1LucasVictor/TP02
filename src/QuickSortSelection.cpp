#include "Sorts.hpp"
void selection(Register v[], int begin, int end, int &comp, int &atrib) {
  Register aux;
  for (int i = end; i > begin; i--) {
    int biggest = 0;
    for (int j = begin; j <= i; j++) {
      if (v[j].key > v[biggest].key) biggest = j;
      comp++;
    }
    aux = v[i];
    v[i] = v[biggest];
    v[biggest] = aux;
    atrib += 3;
  }
}
void partitionS(Register v[], int begin, int end, int &i, int &j, int &comp,
                int &atrib) {
  auto pivot = v[(begin + end) / 2];
  atrib++;
  i = begin;
  j = end;
  Register aux;
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
      atrib += 3;
    }
  }
}
void quickSortS(Register v[], int begin, int end, int &comp, int &atrib) {
  int i, j;
  if ((end - begin + 1) <= 10) {
    selection(v, begin, end, comp, atrib);
  } else if (begin < end) {
    partitionS(v, begin, end, i, j, comp, atrib);
    quickSortS(v, begin, j, comp, atrib);
    quickSortS(v, i, end, comp, atrib);
  }
}
