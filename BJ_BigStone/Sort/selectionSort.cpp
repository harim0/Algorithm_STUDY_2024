#include<bits/stdc++.h>

using namespace std;
// Selection Sort: 가장 작은 것 선택해서 제일 앞으로 보낸다.
int main(){
    int arr[10] = {1,10,5,8,7,6,4,3,2,9}; 
    for(int i=0; i<10; i++){
        int idx=0, minNum = 1e9;
        for(int j=i; j<10; j++){
            if(minNum>arr[j]){
                minNum=arr[j];
                idx=j;
            }
        }
        if(minNum<1e9){
            arr[idx]=arr[i];
            arr[i]=minNum;
        }
    }

    cout<<"Selection Sort\n";
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}