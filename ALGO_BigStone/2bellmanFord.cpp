#include<bits/stdc++.h>
// https://yabmoons.tistory.com/365
using namespace std;

const int n = 6;
int INF = 100000000;
int Dist[n+1];

vector<pair<pair<int, int>, int>> Edge;

void init(){
    fill_n(Dist, n+1, INF);

    Edge.push_back({{1,2},2});
    Edge.push_back({{1,3},5});
    Edge.push_back({{1,4},1});

    Edge.push_back({{2,1},2});
    Edge.push_back({{2,3},3});
    Edge.push_back({{2,2},2});

    Edge.push_back({{3,1},5});
    Edge.push_back({{3,2},3});
    Edge.push_back({{3,4},3});
    Edge.push_back({{3,5},1});
    Edge.push_back({{3,6},5});

    Edge.push_back({{4,1},1});
    Edge.push_back({{4,2},2});
    Edge.push_back({{4,3},3});
    Edge.push_back({{4,5},1});

    Edge.push_back({{5,3},1});
    Edge.push_back({{5,4},1});
    Edge.push_back({{5,6},2});

    Edge.push_back({{6,3},5});
    Edge.push_back({{6,5},2});
}

void Bellman_Ford(){
    Dist[1] = 0;
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j < Edge.size(); j++){
            int src = Edge[j].first.first;
            int dest = Edge[j].first.second;
            int weight = Edge[j].second;
            
            if (Dist[src] == INF) continue;
            if (Dist[dest] > Dist[src] + weight) Dist[dest] = Dist[src] + weight;
        }
    }

    for (int i = 0; i < Edge.size(); i++){
        int src = Edge[i].first.first;
        int dest = Edge[i].first.second;
        int weight = Edge[i].second;
        
        if (Dist[src] == INF) continue;
        if (Dist[dest] > Dist[src] + weight){
            cout << "Graph with negative cycle\n" << endl;
            return;
        }
    }
    cout<<"Normal Graph with no negative cycle\n"<<endl;
}

int main(){
    init();
    Bellman_Ford();

    for(int i=1; i<=n; i++){ 
        cout<<"<"<<i<<"> ";
    }
    cout<<"\n";
    for(int i=1; i<=n; i++){ 
        cout<<" "<<Dist[i]<<"  ";
    }
    cout<<"\n";

    return 0;
}