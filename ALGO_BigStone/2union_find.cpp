#include<bits/stdc++.h>

using namespace std;

int parent[11];

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b); 
    if(a==b) return 1;
    else return 0;
}

int main(){

    for(int i=0; i<11; i++){
        parent[i]=i;
    }
    unionParent(1, 2);
    unionParent(2, 3);
    unionParent(3, 4);
    unionParent(5, 6);
    unionParent(6, 7);
    unionParent(7, 8);

    int n1,n2;
    cin>>n1>>n2;
    cout<<n1<<" 과 "<<n2<<"는 연결?\n";
    cout<<findParent(n1, n2)<<endl;
    cout<<"unionParent 시행\n";
    unionParent(n1, n2);
    cout<<findParent(n1, n2)<<endl;

    return 0;
}