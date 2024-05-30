#include<bits/stdc++.h>

using namespace std;

int glob_a;
int main(){
    int local_a;
    cout<<"glob_a memory 주소: "<<&glob_a<<"\n";
    cout<<"local_a memory 주소: "<<&local_a<<"\n";
    // glob_a memory 주소: 0x102764000
    // local_a memory 주소: 0x16d6a3288
    cout<<"\n";
    cout<<"\n";
    int arr[5] = {1,2,3,4,5};
    int *a = arr;
    cout<<"a: "<<a<<"\n";
    cout<<"a+1: "<<a+1<<"\n";
    cout<<"a+2: "<<a+2<<"\n";
    cout<<"&a[0]: "<<&a[0]<<"\n";
    cout<<"&a[1]: "<<&a[1]<<"\n";
    cout<<"&a[2]: "<<&a[2]<<"\n\n\n";
    cout<<"*(a): "<<*(a)<<"\n";
    cout<<"*(a+1): "<<*(a+1)<<"\n";
    cout<<"*(a+2): "<<*(a+2)<<"\n";
    cout<<"*(&a[0]): "<<*(&a[0])<<"\n";
    cout<<"*(&a[1]): "<<*(&a[1])<<"\n";
    cout<<"*(&a[2]): "<<*(&a[2])<<"\n\n";
    cout<<"\n\n\n";
    cout<<"*&a[0]: "<<*&a[0]<<"\n";
    cout<<"*&a[1]: "<<*&a[1]<<"\n";
    cout<<"*&a[2]: "<<*&a[2]<<"\n\n";
    
    return 0;
}