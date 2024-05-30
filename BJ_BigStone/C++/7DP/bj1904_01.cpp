// 2024-03-11 18:30 CHATGPT --> SO 자괴감
#include<iostream>
#include<vector>

using namespace std;

const int MOD = 15746;
const int MAX_N = 1000000;

int dp[MAX_N + 1];

int main() {
    int N;
    cin >> N;

    // 초기값 설정
    dp[1] = 1;
    dp[2] = 2;

    // Bottom-up 방식으로 dp 배열 채우기
    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    // 결과 출력
    cout << dp[N] << endl;

    return 0;
}
