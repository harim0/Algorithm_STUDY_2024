#include<iostream>
#include<vector>

using namespace std;

int memo_bu[1000001]={0,};
int memo_td[1000001]={0,};

// 아, 4->2->1 이면 3이 0이네. 통과했는데 174316 segmentation fault 이유가 뭐지?
int td_memo(int n1){
    if(n1==0||n1==1||memo_td[n1]>0) return memo_td[n1];
    else{
        memo_td[n1] = td_memo(n1-1) + 1;
        if(n1%3==0){
            int up = td_memo(n1/3);
            if(memo_td[n1]>up+1) memo_td[n1] = up+1;
        }
        if(n1%2==0){
            int up = td_memo(n1/2);
            if(memo_td[n1]>up+1) memo_td[n1] = up+1;
        }
        // cout<<"n1: "<<n1<<", "<<memo_td[n1]<<endl;
        return memo_td[n1];
    }
}

int main(){

    int n;
    cin>>n;

    // Bottom Up (5928KB	4ms)
    memo_bu[0] = memo_bu[1] = 0;

    for(int i=2; i<n+1; i++){
        memo_bu[i] = memo_bu[i-1]+1;
        if(i%3==0){
            if(memo_bu[i]>memo_bu[i/3]+1) memo_bu[i] = memo_bu[i/3]+1;
        }
        if(i%2==0){
            if(memo_bu[i]>memo_bu[i/2]+1) memo_bu[i] = memo_bu[i/2]+1;
        }
        // cout<<"i: "<<i<<", "<<memo_bu[i]<<endl;
    }

    cout<<"Bottom Up: "<<memo_bu[n]<<endl;

    int td_rst = td_memo(n);

    // Top Down (37056KB	36ms)
    cout<<"Top Down: "<<td_rst<<endl;


    return 0;
}