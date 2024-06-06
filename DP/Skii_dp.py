def solution(n, flags):
    dp = [[0]*n for _ in range(n)]
    
    for j in range(n):
        dp[n-1][j] = flags[n-1][j]
    
    for i in range(n-2,-1,-1):
        for j in range(i+1):
            print("flags[",i,"][",j,"]:",flags[i][j],"|| flags[",i+1,"][",j,"]:",flags[i+1][j],", flags[",i+1,"][",j+1,"]:",flags[i+1][j+1])
            dp[i][j] = flags[i][j] + max(dp[i+1][j], dp[i+1][j+1])
    return dp[0][0]

def main(T, n_list, flags_list):
    for _ in range(T):
        for i,n in enumerate(n_list):
            print(solution(n,flags_list[i]))
            
main(2, [5,10],[[[7],[3,8],[8,1,0],[2,7,4,4],[4,5,2,6,5]],[[1], [2, 3], [4, 5, 6], [7, 8, 9, 10], [11, 12, 13, 14, 15], [21, 20, 19, 18, 17, 16], [22, 23, 24, 25, 26, 27, 28], [36, 35, 34, 33, 32, 31, 30, 29], [37, 38, 39, 40, 41, 42, 43, 44, 45], [55, 54, 53, 52, 51, 50, 49, 48, 47, 46]]])