#include<bits/stdc++.h>

using namespace std;

int t,n,m;
int note1[1000004];
int note2[1000004];

int binSearch(int num, int size, int note[]){
    int l=0, r=size-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(note[mid]>num) r=mid-1;
        else if(note[mid]==num) return 1;
        else l=mid+1;
    }
    return 0;
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>note1[j];
        }
        cin>>m;
        for(int j=0; j<m; j++){
            cin>>note2[j];
        }
        sort(note1, note1+n);

        for(int i=0; i<m; i++){
            cout<<binSearch(note2[i], n, note1)<<"\n";
        }
        
    }
    return 0;
}