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

void partitionNR(int *v, int begin, int end, int &i, int &j) {
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

void QuickSortNR(int *v, int n) {
  stack s;
  int left, right, i, j;

  left = 0;
  right = n - 1;
  s.insert(left, right);
  do
    if (right > left) {
      partitionNR(v, left, right, i, j);
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