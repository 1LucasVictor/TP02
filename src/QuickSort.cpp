#include "Sorts.hpp"
void partition(Register v[], int begin, int end, int &i, int &j, int &comp, int &atrib) {
  auto pivot = v[(begin + end) / 2];
  atrib++;
  i = begin; j = end;
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
      atrib+=3;
    }
  }
}
void quickSort(Register v[], int begin, int end, int &comp, int &atrib) {
  int i, j;
  if (begin < end) {
    partition(v, begin, end, i, j, comp, atrib);
    quickSort(v, begin, j, comp, atrib);
    quickSort(v, i, end, comp, atrib);
  }
}