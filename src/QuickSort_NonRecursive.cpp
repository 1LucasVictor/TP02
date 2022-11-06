#include "QuickSorts.hpp"

struct item {
  int left;
  int right;
  item *next;
};
class stack {
 public:
  stack() { top = nullptr; }
  void insert(int left, int right) { top = new item{left, right, top}; }
  item remove() {
    auto aux = top;
    auto aux1 = *aux;
    top = top->next;
    delete aux;
    return aux1;
  }
  int empty() {
    if (top == nullptr) return 1;
    return 0;
  }

 private:
  item *top;
};

void partitionNR(int *v, int begin, int end, int &i, int &j, int &comp,
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
      atrib+=3;
    }
  }
}

void quickSortNR(int *v, int n, int &comp, int &atrib) {
  stack s;
  int left, right, i, j;

  left = 0;
  right = n - 1;
  s.insert(left, right);
  do
    if (right > left) {
      partitionNR(v, left, right, i, j, comp, atrib);
      if ((j - left) > (right - i)) {
        s.insert(left, j);
        left = i;
      } else {
        s.insert(i, right);
        right = j;
      }
    } else {
      auto aux = s.remove();
      right = aux.right;
      left = aux.left;
    }
  while (!s.empty());
}