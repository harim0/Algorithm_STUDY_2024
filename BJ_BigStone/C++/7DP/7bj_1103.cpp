#include<iostream>
#include<cstring>
#include<vector>
#include<utility>

using namespace std;
int board[54][54];
int visited[54][54];
int n, m;
int dt[54][54];
vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

int valid(int y, int x){
    if(y<=0||y>=n||x<=0||x>=n) return 0;
    return 1;
}

int re_longest(int y, int x, int num){
    if(visited[y][x]==1) return -1;
    if(board[y][x]==-1) return num+1;
    int cnt = 0;
    for(int i=0; i<4; i++){
        int ny = y+dirs[i].first*board[y][x];
        int nx = x+dirs[i].second*board[y][x];
        if(valid(ny,nx)){
            visited[ny][nx] = 1;
            cout<<"(ny: "<<ny<<", nx: "<<nx<<")"<<endl;
            cnt = max(cnt, re_longest(ny,nx,num+1));
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ret;
            cin>>ret;
            if(ret=='H') board[i][j] = 0;
            else board[i][j] = ret-'0';
        }
    }
    memset(visited, 0, sizeof(visited));
    cout<<re_longest(0,0,0)<<endl;

    return 0;
}