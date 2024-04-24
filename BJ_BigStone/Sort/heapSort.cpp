#include <iostream>
using namespace std;

const int n = 10;
int heap[n] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

void maxHeapify(int i, int size) {
    int l=2*i+1;
    int r=2*i+2;
    int maxIDX=i;

    if(l<size && heap[l]>heap[i]) maxIDX=l;
    else maxIDX=i;
    if(r<size && heap[r]>heap[maxIDX]) maxIDX=r;
    if(maxIDX!=i){
        swap(heap[i], heap[maxIDX]);
        maxHeapify(maxIDX, size);
    }
}

void buildMAXHeap() {
    for (int i=n/2-1; i>=0; i--)
        maxHeapify(i, n);
}

void heapSort() {
    buildMAXHeap();
    for (int i=n-1; i>0; i--) {
        swap(heap[0], heap[i]);
        maxHeapify(0, i);
    }
}

int main() {
    heapSort();

    cout << "Heap Sort\n";
    for (int i=0; i<n; i++)
        cout << heap[i] << " ";
    cout << "\n";

    return 0;
}
