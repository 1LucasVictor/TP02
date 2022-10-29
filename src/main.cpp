#include <iostream>
#include "QuickSorts.hpp"
using namespace std;
void printVector(int *v, int n) {
    for(int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << endl;
}
int main() {
    int v[] = {3, 8, 6, 5, 7, 4, 1, 2};
    quickSortM(v, 0, 7);
    printVector(v, 8);
    return 0;
}