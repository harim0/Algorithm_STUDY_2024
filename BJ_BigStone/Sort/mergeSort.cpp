#include<bits/stdc++.h>

using namespace std;

const int n = 10;
int arr[n] = {1,10,5,8,7,6,4,3,2,9};
int sorted[n];

void merge(int start, int mid, int end){
    int i=mid, j=mid+1, k=end;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]){
            sorted[k] = arr[j];
            i++;
        }else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        for(int t=i; t<=mid; t++){

        }
    }else{
        for(int t=)
    }
    for(int t) arr[t] = 
}

void mergeSort(int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(start, mid);
        mergeSort(mid+1, end);
        merge(start, mid, end);
    }
}

int main(){

    mergeSort(0,n-1);
    
    cout << "Merge Sort\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}