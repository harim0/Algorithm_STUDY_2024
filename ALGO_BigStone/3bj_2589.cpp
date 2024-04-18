#include <bits/stdc++.h>
// bfs로 전면 수정해야 함~~
using namespace std;

int n, m;
int matrix[52][52] = {0,};
int visited[52][52] = {0,};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int,int>> vec;

void dfs_treasure(int y, int x){
    cout<<"y: "<<y<<", x: "<<x<<endl;
    for(int k=0; k<4; k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<0||nx>m-1||ny<0||ny>n-1) continue;
        if((!visited[ny][nx])&&matrix[ny][nx]){
            visited[ny][nx]=1;
            vec.push_back({ny,nx});
            dfs_treasure(ny,nx);
        }
    }
}
vector<int> fin;
void findMinDist(int size){
    if(fin.size()==size){

    }
    for(auto cont: vec){

    }
}
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            scanf(" %c", &c);
            if(c=='W') matrix[i][j]=0;
            else if(c=='L') matrix[i][j]=1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((!visited[i][j])&&matrix[i][j]){ 
                visited[i][j]=1;
                vec.push_back({i,j});
                dfs_treasure(i,j);
                findMinDist(2);
            }
        }
    }
    return 0;
}
