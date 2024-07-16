#include<bits/stdc++.h>

using namespace std;

vector<int> dir_y = {0,-1,0,1}; // 왼, 상, 우, 하
vector<int> dir_x = {-1,0,1,0};
int w,h;
char board[51][51];
int visited[51];
vector<pair<int,int>> Q;

int findTreasure(int y, int x){

}

int main(){
    cin>>h>>w;
    for(int i=0;i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    findTreasure(0,0);

    return 0;
}