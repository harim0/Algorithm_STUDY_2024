#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N=100;
vector<int> adj[N];
int visited[N]={0,};
int nodeList[]={10,12,14,16,18,20,22,24};
queue<int> Q;

void bfs(int u){
    visited[u] = 1;
    Q.push(u);
    while(Q.size()){
        u = Q.front();
        Q.pop();
        cout<<"u: "<<u<<"\n";
        for(auto v:adj[u]){
            if(!visited[v]){
                visited[v] = visited[u]+1;
                Q.push(v);
            }
        }
    }
}

int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);
    adj[12].push_back(18);
    adj[12].push_back(20);
    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);

    cout<<"-----check------\n";
    for(auto i:nodeList)
        cout<<"i: "<<i<<" -> "<<visited[i]<<"\n";
    cout<<"최단 거리는 "<<visited[24]-1<<"\n";

    return 0;
}