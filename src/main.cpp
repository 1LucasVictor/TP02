#include <iostream>

#include "QuickSorts.hpp"
using namespace std;
#define len 20000


void printKeys(Register r[], int n) {
  for (int i = 0; i < n; i++) {
    cout << r[i].key << " | ";
  }
  cout << endl;
}


int main(int argc, char *argv[]) {
  Register *registers = new Register[len];
  for (int i = 0; i < len; i++) {
    registers[i].key = rand() % 500;
  }
  cout << "Oi" << endl;
  int comp = 0, atrib = 0;
  quickSortM(registers, 0, len-1, comp, atrib);
  // quickSortNR(registers,len, comp, atrib);
  printKeys(registers, len);
  cout << "Comparações: " << comp << "; Atribuições: " << atrib << endl;
  return 0;
}