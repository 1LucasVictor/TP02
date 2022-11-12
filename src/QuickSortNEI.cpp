#include "Sorts.hpp"

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

void partitionEI(Register v[], int begin, int end, int &i, int &j, int &comp,
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
      atrib+=3;
    }
  }
}

void quickSortEI(Register v[], int n, int &comp, int &atrib) {
  stack s;
  int left, right, i, j;

  left = 0;
  right = n - 1;
  atrib += 2;

  s.insert(left, right);
  do {
    comp++;
    if (right > left) {
      partitionEI(v, left, right, i, j, comp, atrib);
      if ((j - left) > (right - i)) {
        comp++;
        s.insert(left, j);
        left = i;
        atrib++;
      } else {
        comp++;
        atrib++;
        s.insert(i, right);
        right = j;
      }
    } else {
      comp++;
      atrib += 3;
      auto aux = s.remove();
      right = aux.right;
      left = aux.left;
    }
  }
  while (!s.empty());
}