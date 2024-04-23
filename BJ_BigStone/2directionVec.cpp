#include<iostream>
#include<vector>

using namespace std;

int mat[3][3];
int visited_sol[3][3]={0,};
int visited[3][3]={0,};

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
// nx, ny range: 0 1 2

bool variable_check(int y, int x){
    if(x<0||y<0||x>2||y>2) return false;
    else return true;
}

void recur_search_sol(int y, int x){
    visited_sol[y][x]=1;
    cout<<"x: "<<x<<", y:"<<y<<endl;
    for(int k=0; k<4; k++){
        int ny = y+dy[k];
        int nx = x+dx[k];
        if(nx<0||ny<0||nx>2||ny>2) continue;
        if(!mat[ny][nx]) continue; // <--- ??? 아 0은 피해야하누(차단)... 길 따라..
        if(visited_sol[ny][nx]) continue;
        recur_search_sol(y+dy[k],x+dx[k]);
    }
}

void recur_search(int j, int i){ // 헷갈리게 하지 말자 개빡침 y먼저 x다음 ~
    if(visited[j][i]) return;
    visited[j][i]=1;
    if(mat[j][i]) cout<<"x: "<<i<<", y:"<<j<<endl; // 이게 시발 문제였누. 0 통과함
    for(int k=0; k<4; k++){
        if(variable_check(j+dy[k],i+dx[k]))
            recur_search(j+dy[k],i+dx[k]);
    }
}

int main(){
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin>>mat[i][j];
    mat[0][0]=1;
    cout<<"***sol***"<<endl;
    recur_search_sol(0,0);
    cout<<"***mine***"<<endl;
    recur_search(0,0);

    return 0;
}
