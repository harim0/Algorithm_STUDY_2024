#include<bits/stdc++.h>

using namespace std;
// Bubble Sort: 첫번째와 두번째 원소, 두번째와 세번째, n-1번째와 n번째 정렬한 뒤,
// 다시 처음으로 돌아가 n-2번째와 n-1번째까지 최대 n(n-1)/2번 정렬한다
// 한 번 돌 때마다 마지막 하나가 정렬된다 <- 거의 모든 상항에서 최악의 성능ㅎ

int main(){
    int arr[10] = {1,10,5,8,7,6,4,3,2,9}; 

    for(int i=0; i<10; i++){
        for(int j=0; j<9-i; j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    cout<<"Bubble Sort\n";
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}