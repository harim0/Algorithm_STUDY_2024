#include<bits/stdc++.h>
// https://blog.naver.com/ndb796/221234424646
// PQ에 마이너스 발상 bb

using namespace std;

const int n = 6;
int INF = 10000000;
typedef pair<int,int> p;
vector<p> graph[n+1];
int dist[n+1];

struct compare{
    bool operator()(const p a, const p b){
        return a.second < b.second; // 작은 것부터 오는 것 TRUE
    }
};

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<p, vector<p>, compare> pq;
    pq.push({start,0});

    cout<<"pq pop order: ";
    while(!pq.empty()){
        int cur = pq.top().first;
        int curDist = pq.top().second;
        cout<<cur<<" ";
        pq.pop();
        if(dist[cur]<curDist) continue; // 최단 거리 아니면
        for(int i=0; i<graph[cur].size(); i++){
            int nxt = graph[cur][i].first;
            int nxtDist = graph[cur][i].second;
            if(dist[cur]+nxtDist<dist[nxt]){
                dist[nxt] = dist[cur]+nxtDist;
                pq.push({nxt, nxtDist});
            }
        }
    }
    cout<<"pq empty!\n";
}

void init(){
    for(int i=1; i<=n; i++) dist[i] = INF;

    graph[1].push_back({2,2});
    graph[1].push_back({3,5});
    graph[1].push_back({4,1});

    graph[2].push_back({1,2});
    graph[2].push_back({3,3});
    graph[2].push_back({2,2});

    graph[3].push_back({1,5});
    graph[3].push_back({2,3});
    graph[3].push_back({4,3});
    graph[3].push_back({5,1});
    graph[3].push_back({6,5});

    graph[4].push_back({1,1});
    graph[4].push_back({2,2});
    graph[4].push_back({3,3});
    graph[4].push_back({5,1});

    graph[5].push_back({3,1});
    graph[5].push_back({4,1});
    graph[5].push_back({6,2});

    graph[6].push_back({3,5});
    graph[6].push_back({5,2});
}


int main(){
    init();
    dijkstra(1);

    for(int i=1; i<=n; i++){ 
        cout<<"<"<<i<<"> ";
    }
    cout<<"\n";
    for(int i=1; i<=n; i++){ 
        cout<<" "<<dist[i]<<"  ";
    }
    cout<<"\n";

    return 0;
}
