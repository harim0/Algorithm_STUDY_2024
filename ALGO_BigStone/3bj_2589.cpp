#include <bits/stdc++.h>
// bfs로 전면 수정
using namespace std;

int n, m;
int matrix[52][52] = {0,};
int visited[52][52] = {0,};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int>> Q;
int mostFarDistTreasure=0;
int Dist=0;

void bfs_treasure(int y, int x){
    cout<<"y: "<<y<<", x: "<<x;
    Dist=0;
    visited[y][x]=1;
    Q.push({y,x});
    while(Q.size()){
        pair cur = Q.front();
        Q.pop();
        y = cur.first;
        x = cur.second;
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(nx<0||nx>m-1||ny<0||ny>n-1) continue;
            if((!visited[ny][nx])&&matrix[ny][nx]){
                visited[ny][nx] = visited[y][x]+1;
                if(Dist<visited[ny][nx]) Dist = visited[ny][nx]-1;
                Q.push({ny,nx});
            }
        }
    }
    cout<<"---> Dist: "<<Dist<<endl;
    if(mostFarDistTreasure<Dist) mostFarDistTreasure = Dist;
}
void display_matrix(){
    cout<<"------matrix-----\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
}
void display_visited(){
    cout<<"----visited-------\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------\n";
}
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            scanf(" %c", &c); // 와." %c" VS "%c"
            if(c=='W') matrix[i][j] = 0;
            else if(c=='L') matrix[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]){ 
                memset(visited, 0, sizeof(visited));
                bfs_treasure(i,j);
                // display_matrix();
                // display_visited();
            }
        }
    }

    cout<<mostFarDistTreasure<<endl;
    return 0;
}
