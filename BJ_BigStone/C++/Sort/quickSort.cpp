#include<bits/stdc++.h>

using namespace std;
// Quick Sort: 적절한 Pivot을 설정해 보다 더 작은 것은 앞으로, 보다 더 큰 것은 뒤로 옮기고
// 둘로 분할된 각각에서 다시 Pivot을 잡아 각각의 크기가 0이나 1이 될 때까지 정렬한다

const int n = 10;
// int arr[] = {2,8,7,1,3,5,6,4};
int arr[] = {1,10,5,8,7,6,4,3,2,9};

int cnt = 1;

int partition(int start, int end){
    cout<<cnt<<") start: "<<start<<", end: "<<end<<endl;
    cnt++;
    int pivot = arr[end];
    int left = start-1;
    for(int right=start; right<end; right++){
        if(arr[right]<=pivot){
            left++;
            swap(arr[right], arr[left]);
            cout<<"--------swap-------- (l: "<<left<<",r:"<<right<<")\n";
            for(int i=0; i<n; i++) cout<<arr[i]<<" ";
            cout<<"\n";
        }
    }
    swap(arr[left+1], arr[end]);
    cout<<"--------swap-------- (l+1: "<<left+1<<",end:"<<end<<")\n";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    return left+1;
}

void quickSort(int start, int end){
    if(start<end){
        int p = partition(start, end);
        cout<<"\n***** < partition p: "<<p<<" > ******"<<endl;
        quickSort(start, p-1);
        quickSort(p+1, end);
    }
}

int main(){

    quickSort(0,n-1);

    cout << "\nQuick Sort\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}