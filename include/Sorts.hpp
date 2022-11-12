#ifndef QS
#define QS

struct Register {
  int key;
  char strings[15][200] = {""};
  int numbers[10];
};

void quickSort(Register v[], int begin, int end, int &comp, int &atrib);
void quickSortM(Register v[], int begin, int end, int &comp, int &atrib);
void quickSortS(Register v[], int begin, int end, int &comp, int &atrib);
void quickSortNR(Register v[], int n, int &comp, int &atrib);

#endif