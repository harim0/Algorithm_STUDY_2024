#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n;
int h[16][16]={-1,};
vector<pair<int, int>> moving = {{0,1},{1,0},{1,1}};
// int calls = 0;

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

    cout<<cnt_possible(0, 1, 0)<<endl;
    // cout<<calls<<endl;

    return 0;
}