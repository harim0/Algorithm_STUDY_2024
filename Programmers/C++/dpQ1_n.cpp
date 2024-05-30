// 0309 18:30
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int memo[32003]={0,}; // 초기값

int solution(int N, int number) {
    int answer = 0;
    memo[N] = 1;
    memo[1] = 2;

    for(int i=0; i<number; i++){
        
    }
    return answer;
}
// 사칙연산이면 +, -, *, /

int main(){
    int rst1 = solution(5,12);

    cout<<"rst1: "<<rst1<<endl;
    return 0;
}
