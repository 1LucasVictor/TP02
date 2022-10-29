int partition(int *v, int begin, int end) {
    int pivotInd = (begin+end)/2;
    int i = begin, j = end;
    while(i < j) {
        while(v[i] < v[pivotInd]) i++;
        while(v[j] > v[pivotInd]) j--;
        if(i < j) {
            if(pivotInd == i) pivotInd = j;
            else if(pivotInd == j) pivotInd = i;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    return pivotInd;
}
void quickSort(int *v, int begin, int end) {
    if(begin < end) {
    int pivotInd = partition(v, begin, end);
    quickSort(v, begin, pivotInd-1);
    quickSort(v, pivotInd+1, end);
    }
}