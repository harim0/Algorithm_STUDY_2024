#include <iostream>
#include <vector>

using namespace std;

int w,h;
int nx, ny;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int con_x, con_y;

void squish(int x, int y, int **matrix, int **visited){
    visited[y][x] = 1;
    cout<<"x: "<<x<<", y: "<<y<<"\n";
    for(int k=0; k<4; k++){
        nx = x+dx[k];
        ny = y+dy[k];
        if(nx<0||nx>w-1||ny<0||ny>h-1) continue;
        if(visited[ny][nx]) continue;
        if(!matrix[ny][nx]) continue;
        con_x=nx;
        con_y=ny;
        squish(nx,ny,matrix,visited);
    }
}
// 사방이 다 0이면 ++하는 알고리즘을 어떻게 짜야 할까나

int main(){
    cin>>w>>h;

    int **matrix = new int*[h];
    int **visited = new int*[h];
    for(int i=0; i<h; i++){
        matrix[i] = new int[w];
        visited[i] = new int[w]{0,};
        for(int j=0; j<w; j++){
            cin>>matrix[i][j];
        }
    }

    int iter_x=0, iter_y=0;
    int rst = 0;

    while(iter_x<w&&iter_y<h){
        squish(iter_x,iter_y,matrix, visited);
        // 그 다음 matrix 1인 부분을 찾아야 하는데..
        bool found = false;
        for(int j=con_y; j<h; j++){
            for(int i=con_x; i<w; i++){
                if(matrix[j][i]){
                    iter_x=i;
                    iter_y=j;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        rst++;
    }

    cout<<"rst: "<<rst<<"\n";

    return 0;
}