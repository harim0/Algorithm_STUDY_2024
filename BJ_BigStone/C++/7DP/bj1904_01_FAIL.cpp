// 2024-03-11 12:30
#include<iostream>
#include<vector>

#define MAX_N 1000000 

using namespace std;

unsigned int memo[MAX_N + 1][MAX_N + 1] = {0};

// "재귀 호출에 따른 스택 크기는 계산이 어려우니 1 만번을 초과하지 않도록 한다"
int combination(int a, int b){ // bus error
    if(memo[a][b]>0){
        return memo[a][b];
    }else{
        if(a==b||b==0){
            memo[a][b] = 1;
        }else if(b==1){
            memo[a][b] = a;
        }else{
            memo[a][b] = (combination(a-1,b-1)+combination(a-1,b))%15746; 
        }
        memo[a][a-b] = memo[a][b];
        return memo[a][b];
    }
}

int main(){
    int n;
    cin>>n;

    unsigned int answer = 0;
    answer += 1;
    for(int i=1; i<=n/2; i++){
        cout<<"\tn: "<<n<<", i: "<<i<<", answ: "<<answer<<endl;
        answer += combination(n-i,i);
        answer %= 15746;
    }
    cout<<answer%15746<<endl;

    return 0;
}