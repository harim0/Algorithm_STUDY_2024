#include <bits/stdc++.h>

using namespace std;

int pos = 1;
int bf_converse(){
    if(pos==1) pos=2;
    else pos=1;
    return pos;
}
int bit_masking(){
    pos = pos^3;
    return pos;
}
int main(){
    
    for(int i=0; i<5; i++){
        cout<<bf_converse()<<endl;
    }
    
    cout<<"changed\n";
    pos = 1;
    for(int i=0; i<5; i++){
        cout<<bit_masking()<<endl;
    }

    cout<<"\n"; // pos = 2
    cout<<(1==pos-1)<<endl; // true
    cout<<((1==pos)-1)<<endl; // true
    cout<<(1==(pos-1))<<endl; // true
    cout<<"\n"; 
    cout<<(2==pos-1)<<endl; // <- ?
    cout<<((2==pos)-1)<<endl; // false 연산 
    cout<<(2==(pos-1))<<endl; // false 등호

    return 0;
}