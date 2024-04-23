#include <iostream>
#include <vector>

using namespace std;

int w,h;
int nx, ny;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

void squish(int x, int y, int **matrix, int **visited){
    visited[y][x] = 1;
    cout<<"<x: "<<x<<", y: "<<y<<">\n";
    for(int k=0; k<4; k++){
        nx = x+dx[k];
        ny = y+dy[k];
        if(nx<0||nx>w-1||ny<0||ny>h-1) continue;
        if(visited[ny][nx]) continue;
        if(!matrix[ny][nx]) continue;
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

    int rst = 0;
    for(int j=0; j<h; j++){
        for(int i=0; i<w; i++){
            if(visited[j][i]) continue;
            if(!matrix[j][i]) continue;
            rst++;
            squish(i,j,matrix, visited);
            cout<<"************\n";
        }
    }

    cout<<"rst: "<<rst<<"\n";

    return 0;
}