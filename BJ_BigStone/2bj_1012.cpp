#include<bits/stdc++.h>
// 이건 누가 봐도 인접 리스트로 접근해야...?

using namespace std;
const int N = 52;

int T;
int W,H,K;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int matrix[N][N]={0,};
int visited[N][N]={0,};

void dfs_bachoo(int y, int x){
    visited[y][x]=1;
    for(int c=0; c<4; c++){
        int ny = y+dy[c];
        int nx = x+dx[c];
        if(nx<0||nx>W-1||ny<0||ny>H-1) continue;
        if((!visited[ny][nx])&&matrix[ny][nx]) dfs_bachoo(ny,nx);
    }
}

int main()
{
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>W>>H>>K;
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));

        for(int j=0; j<K; j++){
            int x,y;
            cin>>x>>y;
            matrix[y][x]=1;
        }

        int rst=0;
        for(int y=0; y<H; y++){
            for(int x=0; x<W; x++){
                if((!visited[y][x])&&matrix[y][x]){ 
                    dfs_bachoo(y,x);
                    rst++;
                }
            }
        }
        cout<<rst<<"\n";
    }
    return 0;
}