#include<bits/stdc++.h>

using namespace std;

int n;
int S[11];
int B[11];
int visited[11];

int findMinDiff(int s, int b, int cnt){
    int minDiff = 1000000000;
    if(cnt>0) minDiff = abs(s-b);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            minDiff = min(minDiff, findMinDiff(s*S[i],b+B[i], cnt+1));
            visited[i] = 0;

        }
    }
    return minDiff;
}

int minDiff2 = 1000000000;
void findMinDiff2(int idx, int s, int b, int cnt){
    if(idx==n){
        if (cnt>0){
            minDiff2=min(minDiff2, abs(s-b));
        }
        return;
    }
    findMinDiff2(idx+1, s, b, cnt);
    findMinDiff2(idx+1, s*S[idx], b+B[idx], cnt+1);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>S[i]>>B[i];
    }
    memset(visited, 0, sizeof(visited));
    // cout<<findMinDiff(1,0,0)<<endl;
    findMinDiff2(0,1,0,0);
    cout<<minDiff2<<endl;

    return 0;
}