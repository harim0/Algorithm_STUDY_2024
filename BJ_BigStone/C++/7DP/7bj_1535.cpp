#include<iostream>
#include<cstring>

using namespace std;

int n;
int L[20];
int J[20];

// 1. 완전 탐색 방법
int visited[20];
int BF_maxJoy(int l, int j){
    int joy = j;
    for(int k=0; k<n; k++){
        if(!visited[k]&&l-L[k]>0){
            visited[k] = 1;
            joy=max(joy, BF_maxJoy(l-L[k], j+J[k]));
            visited[k] = 0;
        }
    }
    return joy;
}

int maxJoy = 0;
void BF2_maxJoy(int l, int j, int i){
    if(l<=0||i>=n){
        if(maxJoy<j) maxJoy = j;
        return;
    }
    BF2_maxJoy(i+1, l-L[i], j+J[i]);
    BF2_maxJoy(i+1, l, j);
}

// 2. Memoization 방법
int memo[101][20];
int memo_maxJoy(int l, int i){
    if(memo[l][i]) return memo[l][i];
    int joy = 0;
    for(int k=0; k<n; k++){
        if(l-L[k]>0) { 
            joy = max(joy, J[k]+memo_maxJoy(l-L[k], k));
        }
    }
    memo[l][i] = joy;
    return joy;
}

// 3. DP 방법
int dp_table[100];
int dp_maxJoy(){
    for(int k=0; k<n; k++){
        for(int l=100; l>=L[k]; l--){
            cout<<"k: "<<k<<", l: "<<l<<", L[k]: "<<L[k]<<", J[k]: "<<J[k];
            cout<<" \t dp["<<l<<"]="<<dp_table[l]<<" / J[k]+dp["<<l-L[k]<<"]="<<J[k]+dp_table[l-L[k]]<<endl;
            dp_table[l] = max(dp_table[l], J[k]+dp_table[l-L[k]]);
        }
        cout<<endl;
    }
    return dp_table[99];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>L[i];
    for(int i=0; i<n; i++)
        cin>>J[i];
    
    // memset(visited, 0, sizeof(visited));
    // cout<<BF_maxJoy(100,0)<<endl;

    BF2_maxJoy(100,0,0);
    cout<<maxJoy<<endl;

    // memset(memo, 0, sizeof(visited));
    // cout<<memo_maxJoy(100,0)<<endl;

    // memset(dp_table, 0, sizeof(dp_table));
    // cout<<dp_maxJoy()<<endl;

    return 0;
}