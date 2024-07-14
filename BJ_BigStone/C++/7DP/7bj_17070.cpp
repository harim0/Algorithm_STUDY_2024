#include<iostream>
#include<vector>
#include<utility>
#include <cstring>

using namespace std;

int n;
int h[20][20];
int dt[20][20][3];
vector<pair<int, int>> moving = {{0,1},{1,0},{1,1}};
// int calls = 0;
int check(int y, int x, int dir){
    if(y>=n||x>=n) return 0;
    if(dir==0||dir==1){
        if(!h[y][x]) return 1;
    }else if(dir==2){
        if((!h[y][x])&&h[y-1][x]==0&&h[y][x-1]==0) return 1;
    }
    return 0;
}

int dp_possible(int y, int x, int dir){
    dt[0][1][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i,j+1,0)) dt[i][j+1][0]+=dt[i][j][0];
            if(check(i,j+1,0)) dt[i][j+1][0]+=dt[i][j][2];

            if(check(i+1,j,1)) dt[i+1][j][1]+=dt[i][j][1];
            if(check(i+1,j,1)) dt[i+1][j][1]+=dt[i][j][2];

            if(check(i+1,j+1,2)) dt[i+1][j+1][2]+=dt[i][j][0];
            if(check(i+1,j+1,2)) dt[i+1][j+1][2]+=dt[i][j][1];
            if(check(i+1,j+1,2)) dt[i+1][j+1][2]+=dt[i][j][2];
        }
    }
    return dt[n-1][n-1][0]+dt[n-1][n-1][1]+dt[n-1][n-1][2];
}

int cnt_possible(int y, int x, int dir){
    // calls++;
    if(y==n-1&&x==n-1) return 1;
    int cnt = 0;
    for(int i=0; i<3; i++){
        if((dir==0&&i==1)||(dir==1&&i==0)) continue;
        int ny=y+moving[i].first;
        int nx=x+moving[i].second;
        if (ny<n&&nx<n&&h[ny][nx]==0){
            if(i==2&&(h[ny-1][nx]==1||h[ny][nx-1]==1)) continue;
            cnt+=cnt_possible(ny, nx, i);
        }
    }
    return cnt;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>h[i][j];

    // cout<<cnt_possible(0, 1, 0)<<endl;
    memset(dt,0,sizeof(dt));
    cout<<dp_possible(0, 1, 0)<<endl;
    // cout<<calls<<endl;

    return 0;
}