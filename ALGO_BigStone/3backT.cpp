#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
const int n=3;
vector<int> vec;
int matrix[n][n]={{10,20,30},{15,25,35},{30,50,70}};
int visited[n][n]={0,};

void print(){
    for(int i: vec) cout<<i<<" ";
    cout<<"\n";
}
void go(int y, int x){
    if(y==n-1&&x==n-1){ 
        print();
        return;
    }
    for(int k=0; k<4; k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<0||nx>n-1||ny<0||ny>n-1) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        vec.push_back(matrix[ny][nx]);
        go(ny,nx);
        visited[ny][nx]=0;
        vec.pop_back();
    }
}

int main(){
    visited[0][0]=1;
    vec.push_back(matrix[0][0]);
    go(0,0);

    return 0;
}