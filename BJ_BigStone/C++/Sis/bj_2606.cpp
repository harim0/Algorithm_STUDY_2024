#include<bits/stdc++.h>

using namespace std;
int n,e;
vector<int> network[101];
int visited[101];

int wormVirus(int i){
    visited[i] = 1;
    int cnt = 1;
    for(int k=0; k<network[i].size(); k++){
        if(!visited[network[i][k]]){
            cnt+=wormVirus(network[i][k]);
        }
    }
    return cnt;
}

int main(){
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        network[x].push_back(y);
        network[y].push_back(x);
    }

    memset(visited,0,sizeof(visited));
    cout<<wormVirus(1)-1<<endl;

    return 0;
}