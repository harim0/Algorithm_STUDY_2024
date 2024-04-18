#include<bits/stdc++.h>

using namespace std;

int matrix[52][52]={0,};
int visited[52][52]={0,};
int n,l,r;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

queue<pair<int,int>> unionPop;
int sumPop = 0;

void dfs_popMove(int y, int x){
    visited[y][x]=1;
    sumPop+=matrix[y][x];
    unionPop.push({y,x});
    for(int k=0; k<4; k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<0||nx>n-1||ny<0||ny>n-1) continue;
        if(visited[ny][nx]) continue;
        if(abs(matrix[ny][nx]-matrix[y][x])<=r&&abs(matrix[ny][nx]-matrix[y][x])>=l){
            dfs_popMove(ny,nx);
        }
    }

}
void movingPop(){
    int val = sumPop/unionPop.size();
    while(unionPop.size()){
        pair p = unionPop.front();
        matrix[p.first][p.second]=val;
        unionPop.pop();
    }
}

int main(){
    cin>>n>>l>>r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];

    int MovDay=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ // 반복과 종료조건을 재정의해야 함
            sumPop=0;
            memset(visited,0,sizeof(visited));
            dfs_popMove(i,j);
            if(sumPop>0){
                movingPop();
                MovDay++;
            }
        }
    }
    cout<<MovDay<<endl;
    return 0;
}