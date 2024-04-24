#include<bits/stdc++.h>

using namespace std;

const int n = 10;
int arr[] = {1,10,5,8,7,6,4,3,2,9};
int partition(int start, int end){
    int pivot = arr[start];
    int cnt = 0;
    for(int i=start+1; i<=end; i++){
        if(arr[i]<=pivot) cnt++;
    }
    int pivotIDX = start+cnt;
    swap(arr[pivotIDX], arr[start]);

    int i = start, j = end;
    while(i<pivotIDX&&j>pivotIDX){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pivotIDX&&j>pivotIDX) swap(arr[i++], arr[j--]);
    }
    return pivotIDX;
}

void quickSort(int start, int end){
    if(start>=end) return;
    int p = partition(start, end);
    quickSort(start, p-1);
    quickSort(p+1, end);
}
int main(){

    quickSort(0,n-1);
    
    cout << "Quick Sort\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}