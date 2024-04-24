#include<bits/stdc++.h>

using namespace std;
// Insertion Sort: k번째 원소를 1부터 k-1까지와 비교하여 적절한 위치에 끼워넣는다

int main(){
    int arr[10] = {1,10,5,8,7,6,4,3,2,9}; 

    for(int i=0; i<9; i++){
        int j=i;
        while(j>=0&&arr[j]>arr[j+1]){
            int tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            j--;
        }
    }

    cout<<"Insertion Sort\n";
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}