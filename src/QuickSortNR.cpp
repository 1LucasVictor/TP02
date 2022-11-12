#include "Sorts.hpp"

int partitionNR(Register v[], int l, int h, int &comp, int &atrib)
{
    auto x = v[h];
    int i = (l - 1);
    atrib+=2;
 
    for (int j = l; j <= h - 1; j++) {
        comp++;
        if (v[j].key <= x.key) {
            i++;
            auto temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            atrib += 3;
        }
    }
    auto temp = v[i+1];
    v[i+1] = v[h];
    v[h] = temp;
    atrib += 3;
    return (i + 1);
}

void quickSortNR(Register v[], int begin, int end, int &comp, int &atrib)
{
    if (begin < end) {
        int p = partitionNR(v, begin, end, comp, atrib);
        atrib++;
        quickSortNR(v, begin, p - 1, comp, atrib);
        quickSortNR(v, p + 1, end, comp, atrib);
    }
}