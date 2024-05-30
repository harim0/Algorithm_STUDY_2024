#include<bits/stdc++.h>

using namespace std;

int matrix[52][52]={0,};
int visited[52][52]={0,};
int n,l,r;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

queue<pair<int,int>> unionPop;
int sumPop = 0;
int dfs_len = 0;
int visitedSum = 0;
int noDiff = 0;

void dfs_popMove(int y, int x){
    // cout<<"y: "<<y<<", x: "<<x<<endl;
    visited[y][x]=1;
    sumPop+=matrix[y][x];
    visitedSum++;
    dfs_len++;
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
void display_matrix(){
    cout<<"------matrix-----\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
}
void display_visited(){
    cout<<"----visited-------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
}
void movingPop(){
    int val = sumPop/unionPop.size();
    while(unionPop.size()){
        pair p = unionPop.front();
        // cout<<"POP::::"<<p.first<<", "<<p.second<<endl;
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
    
    while(noDiff!=n*n){
        memset(visited,0,sizeof(visited));
        visitedSum=0;
        noDiff=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ // 반복과 종료조건을 재정의해야 함
                if(!visited[i][j]){
                    sumPop=0;
                    dfs_len=0;
                    dfs_popMove(i,j);
                    // cout<<"dfs_len: "<<dfs_len<<endl;
                    movingPop();
                    if(dfs_len==1) noDiff++;
                    // cout<<"---------------------\n";
                    // cout<<"visitedSum: "<<visitedSum<<endl;
                    // cout<<"noDiff: "<<noDiff<<endl;
                    // cout<<"MovDay: "<<MovDay<<endl;
                    // cout<<"---------------------\n";
                    // display_visited();
                    // display_matrix();
                    if(noDiff!=n*n&&visitedSum==n*n&&sumPop>0){ // visited가 다 된 경우에
                        // cout<<"-------sumPop after-----\n";
                        MovDay++;
                    }
                }
            }
        }
    }
    cout<<MovDay<<endl;
    return 0;
}