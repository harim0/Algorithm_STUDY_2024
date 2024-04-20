#include<bits/stdc++.h>

using namespace std;

int getParent(int parent[], int x){
    if(parent[x]==x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b); 
    if(a==b) return 1;
    else return 0;
}

int main(){
    int parent[11];

    for(int i=0; i<11; i++){
        parent[i]=i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    int n1,n2;
    cin>>n1>>n2;
    cout<<n1<<" 과 "<<n2<<"는 연결?\n";
    cout<<findParent(parent, n1, n2)<<endl;
    cout<<"unionParent 시행\n";
    unionParent(parent, n1, n2);
    cout<<findParent(parent, n1, n2)<<endl;

    return 0;
}