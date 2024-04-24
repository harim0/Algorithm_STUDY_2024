#include<bits/stdc++.h>

using namespace std;
// Selection Sort: 첫번째, 두번째...부터 끝까지 훑어서 최소값을 찾아 앞으로 옮긴다

const int n = 10;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main(){
    int arr[10] = {1,10,5,8,7,6,4,3,2,9}; 
    
    selectionSort(arr, n);

    cout<<"Selection Sort\n";
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}