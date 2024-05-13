// Thinking Greedy...1번일 때 최대가 2번일 때도 최대를 보장하나 문제에서? NoNo..
// DP가 Greedy가 아니었나? 그저 BF를 효율적으로 Memoization 사용한 거였나?
// 모든 경우의 수 tCw > t^2..사고다 <- 아니 스케쥴 표로 생각하면? <- 붙어있다는 보장 없잖.
// 2024-05-12-4:30 모르겠음 ㄹㅇ -> 시청 => 2^30(1<=W<=30)

#include <bits/stdc++.h>
#define nXOR 3

using namespace std;

int dp_matrix[1004][2][34];
int given_plum[1004]={0,};
int t,w;

// 재귀를 쓰는 타이밍, 값을 업데이트하는 타이밍 ===> 재귀->++
// 옆에서 오는 것 +1 VS pos 바꿔서 오는 것 ===> stay VS move (limit 조건)

int dp(int time, int pos, int limit){
    if(time>t) return 0; // 기저 사례에서 0 반환, (WRONG) time==t -> Matrix 반환
    if (dp_matrix[time][pos][limit] != -1) return dp_matrix[time][pos][limit];

    int move = limit>0 ? dp(time + 1, pos^nXOR, limit - 1) : 0;
    dp_matrix[time][pos][limit] = max(dp(time + 1, pos, limit), move);
    if(given_plum[time]==pos) dp_matrix[time][pos][limit]+=1;

    return dp_matrix[time][pos][limit];
}

int main(){
    memset(dp_matrix, -1, sizeof(dp_matrix));
    cin>>t>>w;
    for(int i=1; i<=t; i++) cin>>given_plum[i];

    int rst = max(dp(0, 1, w), dp(0, 1^nXOR, w-1));
    cout<<rst<<endl;

    return 0;
}