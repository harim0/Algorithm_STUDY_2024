#include<bits/stdc++.h>

using namespace std;

const int n = 10;
int cnt = 1;
int sorted[n];
int arr[n] = {4,2,8,6,0,5,1,7,3,9};

void merge(int start, int mid, int end){
    cout<<"\t++ "<<cnt<<") start: "<<start<<", end: "<<end<<endl;
    cnt++;
    int i=start, j=mid+1, k=start;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            sorted[k++] = arr[i++];
        }else{
            sorted[k++] = arr[j++];
        }
    }
    while(i <= mid){
        sorted[k++] = arr[i++];
    }
    while(j <= end){
        sorted[k++] = arr[j++];
    }
    cout<<"\t....sorting....";
    for(int t = start; t <= end; t++){
        arr[t] = sorted[t];
        cout<<arr[t]<<" ";
    }
    cout<<"\n";
}

void mergeSort(int start, int end){
    cout<<"-) st: "<<start<<", en: "<<end<<endl;
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(start, mid);
        mergeSort(mid+1, end);
        merge(start, mid, end);
    }
}

int main(){

    mergeSort(0,n-1);
    
    cout << "\nMerge Sort\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}