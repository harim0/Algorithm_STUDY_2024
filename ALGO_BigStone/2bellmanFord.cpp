#include<bits/stdc++.h>
// https://yabmoons.tistory.com/365
using namespace std;

const int n = 10;
int Dist[n];
int INF = 100000000;

vector<pair<pair<int, int>, int>> Edge;

void Bellman_Ford(){
    Dist[1] = 0;
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j < Edge.size(); j++){
            int from = Edge[j].first.first;
            int to = Edge[j].first.second;
            int weight = Edge[j].second;
            
            if (Dist[from] == INF) continue;
            if (Dist[to] > Dist[from] + weight) Dist[to] = Dist[from] + weight;
        }
    }

    for (int i = 0; i < Edge.size(); i++){
        int from = Edge[i].first.first;
        int to = Edge[i].first.second;
        int weight = Edge[i].second;
        
        if (Dist[from] == INF) continue;
        if (Dist[to] > Dist[from] + weight){
            cout << "Graph with negative cycle\n" << endl;
            return;
        }
    }
    cout<<"Normal Graph with no negative cycle\n"<<endl;
}

int main(){

    return 0;
}