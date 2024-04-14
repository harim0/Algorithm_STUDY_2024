#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N=101;
int matrix[N][N];
int visited[N][N]={0,};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue<pair<int,int>> Q;
int h,w;

void bfs_carrot(int init_x,int init_y){
    Q.push(make_pair(init_y,init_x));
    visited[init_y][init_x]=1;
    while(Q.size()){
        pair front = Q.front();
        Q.pop();
        init_y = front.first;
        init_x = front.second;
        for(int k=0; k<4; k++){
            int nx=init_x+dx[k];
            int ny=init_y+dy[k];
            if(nx<0||nx>w-1||ny<0||ny>h-1) continue;
            if((!visited[ny][nx])&&matrix[ny][nx]){
                visited[ny][nx]=visited[init_y][init_x]+1;
                Q.push(make_pair(ny,nx));
            }
        }

    }
}

int main(){
    cin>>h>>w;
    int init_x,init_y;
    int final_x, final_y;
    cin>>init_y>>init_x;
    cin>>final_y>>final_x;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>matrix[i][j];
    
    bfs_carrot(init_x,init_y);

    cout<<"최단 거리: "<<visited[final_y][final_x]<<"\n";

    return 0;
}