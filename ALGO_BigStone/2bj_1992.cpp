#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int matrix[65][65]={0,};
int visited[65][65]={0,};

int N;

void dfsQuadTreeZip(int y, int x, int dst_y, int dst_x, int sum, int cnt){
    visited[y][x]=1;
    cnt+=1;
    sum+=matrix[y][x];
    // cout<<"y: "<<y<<", x: "<<x<<"\tval:"<<matrix[y][x]<<endl;
    // cout<<"dst_y: "<<dst_y<<", dst_x: "<<dst_x<<"\tval:"<<matrix[y][x]<<endl;
    if((cnt==(dst_y-y)*(dst_x-x))&&(sum==cnt||sum==0)){
        cout<<matrix[y][x];
    }else if((cnt==(dst_y-y)*(dst_x-x))&&(sum!=cnt&&sum!=0)){
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0||nx>dst_x-1||ny<0||ny>dst_y-1) continue;
            if((!visited[ny][nx])){
                sum = cnt = 0;
                cout<<"(";
                dfsQuadTreeZip(ny, nx, dst_y/2, dst_x/2, sum, cnt); // lu
                dfsQuadTreeZip(ny, dst_x/2, dst_y/2, dst_x, sum, cnt); // ru
                dfsQuadTreeZip(dst_y/2, nx, dst_y, dst_x/2, sum, cnt); // ld
                dfsQuadTreeZip(dst_y/2, dst_x/2, dst_y, dst_x, sum, cnt); // rd
                cout<<")";
            }
        }
    }else{
        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0||nx>dst_x-1||ny<0||ny>dst_y-1) continue;
            if((!visited[ny][nx])) dfsQuadTreeZip(ny, nx, dst_y, dst_x, sum, cnt);
        }
    }

}

// 재귀로 주어진 범위 내 값이 다 동일하면 압축. 아니면 재귀로 Quad
void display(){
    cout<<"---------------\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------\n";
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &matrix[i][j]);
        }
    }
    dfsQuadTreeZip(0,0,N,N,0,0);

    return 0;
}