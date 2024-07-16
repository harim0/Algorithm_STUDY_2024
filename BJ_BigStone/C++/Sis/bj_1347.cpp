#include<bits/stdc++.h>

using namespace std;

int n;
char c;
int dir_idx = 0;
vector<int> y_dir={-1,0,1,0}; // 0(남),1(서),2(북),3(동)
vector<int> x_dir={0,1,0,-1};

char board[100][100];

int main(){
    cin>>n;
    int cur_y = 50;
    int cur_x = 50;
    memset(board, '#', sizeof(board));
    board[cur_y][cur_x] = '.';

    int min_x = cur_x;
    int min_y = cur_y;
    int max_x = cur_x;
    int max_y = cur_y;
    for(int i=0; i<n; i++){
        cin>>c;
        if(c=='R') dir_idx = (dir_idx+1)%4;
        else if(c=='L') dir_idx = (dir_idx+3)%4;
        else{
            cur_y+=y_dir[dir_idx];
            cur_x+=x_dir[dir_idx];
            min_x = min(min_x, cur_x);
            min_y = min(min_y, cur_y);
            max_x = max(max_x, cur_x);
            max_y = max(max_y, cur_y);
            board[cur_y][cur_x] = '.';
            // cout<<"y: "<<cur_y<<", x: "<<cur_x<<endl;
        }
    }
    // cout<<"min - "<<min_y<<","<<min_x<<"/ max - "<<max_y<<","<<max_x<<endl;
    for(int i=max_y; i>=min_y; i--){
        for(int j=max_x; j>=min_x; j--){
            cout<<board[i][j];
        }
        cout<<endl;
    }

    return 0;
}