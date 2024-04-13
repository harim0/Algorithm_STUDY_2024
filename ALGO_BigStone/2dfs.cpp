#include<iostream>
#include<vector>

using namespace std;

const int n = 5;
int visited[n]={0,}; // visited 하나만 []로 했을 때는 됐는데?
int visited2[n]={0,}; // n 없이 공란으로 나두었을 때 dfs2 동작 안 함... 왜?

void dfs(int u, vector<int> adj[]){ // 1 돌다리도 두들겨보자
    visited[u] = 1;
    cout<<"u: "<<u<<endl;
    for(auto v: adj[u]){
        if(!visited[v]) dfs(v, adj);
    }
    cout<<"dfs 종료!\n";
}
void dfs2(int u, vector<int> adj2[]){ // 2 못 먹어도 고
    if(visited2[u]) return;
    visited2[u] = 1;
    cout<<"u: "<<u<<endl;
    for(auto v: adj2[u]){
        dfs2(v, adj2);
    }
}

int main(){
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    dfs(0,adj);
    cout<<"-----------------\n";
    dfs2(0,adj);
    return 0;
}