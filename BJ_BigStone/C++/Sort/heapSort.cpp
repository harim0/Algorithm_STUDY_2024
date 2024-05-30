#include <iostream>
using namespace std;

const int n = 15;
int heap[n] = {1,3,5,7,9,11,13,15,14,12,10,8,6,4,2};
// int heap[n] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

// 배열을 최대 힙으로 구성하고, 루트(가장 큰 값)를 반복적으로 배열의 끝으로 옮기는(삭제) 과정을 통해 정렬 INPLACE

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
        maxHeapify(0, i);
        swap(heap[0], heap[i]);
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
