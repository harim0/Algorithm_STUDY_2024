#include<iostream>
#include<cstring>

using namespace std;

int w[16][16] = {0,};
int dt[1<<16][16];
int n;

int tsp(int curr, int visited){
    // cout << "visited: " << bitset<16>(visited).to_string().substr(16-n) << " (curr: "<<curr<<")"<<endl;
    if(visited==(1<<n)-1){
        cout<<endl;
        return w[curr][0]?w[curr][0]:1e9;
    }
    if(dt[visited][curr]!=-1){
        return dt[visited][curr];
    }
    int rst = 1e9;
    for(int i=0; i<n; i++){
        if(!(visited&(1<<i))&&w[curr][i]!=0){
            rst = min(rst, w[curr][i]+tsp(i, visited|(1<<i)));
        }
    }
    dt[visited][curr] = rst;
    return dt[visited][curr];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>w[i][j];
        }
    }
    memset(dt, -1, sizeof(dt));
    cout<<tsp(0,1)<<endl;

    return 0;
}