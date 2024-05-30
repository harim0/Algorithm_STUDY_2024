#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include<bits/stdc++.h> // 이거 하나로 와.

using namespace std;

const int N = 102;
int matrix[N][N];
int visited[N][N]={0,};
queue<pair<int,int>> Q;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int h,w;

void minDisBFS(int y, int x){
    visited[y][x]=1;
    Q.push(make_pair(y,x));
    while(Q.size()){
        pair fr = Q.front();
        Q.pop();
        x = fr.second;
        y = fr.first;
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0||nx>w-1||ny<0||ny>h-1) continue;
            if((!visited[ny][nx])&&matrix[ny][nx]){
                visited[ny][nx]=visited[y][x]+1;
                Q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(){
    cin>>h>>w;
    for(int i=0; i<h; i++){
        string ss;
        cin>>ss;
        for(int j=0; j<w; j++)
            matrix[i][j]=ss[j]-'0';
    }

    /*
    scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    } 
    */


    minDisBFS(0,0);

    cout<<visited[h-1][w-1];

    return 0;
}