#include<bits/stdc++.h>

using namespace std;

int N;
int matrix[102][102]={0,};
int visited[102][102]={0,};

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs_rainy(int y, int x, int max_num){
    visited[y][x] = 1;
    for(int k=0; k<4; k++){
        int ny = y+dy[k];
        int nx = x+dx[k];
        if(nx<0||nx>=N||ny<0||ny>=N) continue;
        if((!visited[ny][nx])&&matrix[ny][nx]>max_num){
            dfs_rainy(ny,nx,max_num);
        }
    }
}
// void display(){
//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             cout<<visited[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
int rstMAX = 0;

int main(){
    cin>>N;
    int max_n=0;
    int min_n=100;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]>max_n) max_n = matrix[i][j];
            if(matrix[i][j]<min_n) min_n = matrix[i][j];
        }
    }

    for(int num=min_n; num<max_n; num++){
        // int** visited=new int*[N];
        for(int y=0; y<N; y++) memset(visited[y], 0, N * sizeof(int)); 

        int rst = 0;
        for(int y=0; y<N; y++){
            // visited[y]=new int[N]{0,};
            for(int x=0; x<N; x++){
                if((!visited[y][x])&&matrix[y][x]>num){
                    dfs_rainy(y,x,num);
                    rst++;
                }
            }
        }
        // display();
        if(rst>rstMAX) rstMAX = rst;
    }
    cout<<rstMAX;
    return 0;
}