cnum = 1001
def solution(n, k_rst, h_rst):
    dp = [[0 if j==0 or i==0 else -1 for j in range(cnum)] for i in range(cnum)]
    for k in range(1, n+1):
        for h in range(1, n+1):
            if (k_rst[k-1][0]=='W' and h_rst[h-1][0]=='L' and k_rst[k-1][1]>h_rst[h-1][1]) or\
    (k_rst[k-1][0]=='L' and h_rst[h-1][0]=='W' and k_rst[k-1][1]<h_rst[h-1][1]):
                first = dp[k-1][h-1]+k_rst[k-1][1]+h_rst[h-1][1]
            else:
                first = 0
            second = dp[k][h-1]
            third = dp[k-1][h]
            fourth = dp[k-1][h-1]
            print('first: ',first,', second: ',second,', third: ',third,', fourth: ',fourth)
            dp[k][h] = max(first,max(second,max(third,fourth)))
    return dp[n][n]

# def solution(n, k_rst, h_rst):
#     dp = [[0 if j==0 or i==0 else -1 for j in range(cnum)] for i in range(cnum)]
#     for k in range(0, n):
#         for h in range(0, n):
#             if (k_rst[k][0]=='W' and h_rst[h][0]=='L' and k_rst[k][1]>h_rst[h][1]) or\
#     (k_rst[k][0]=='L' and h_rst[h][0]=='W' and k_rst[k][1]<h_rst[h][1]):
#                 first = dp[k-1][h-1]+k_rst[k][1]+h_rst[h][1]
#             else:
#                 first = 0
#             second = dp[k][h-1]
#             third = dp[k-1][h]
#             fourth = dp[k-1][h-1]
#             print('first: ',first,', second: ',second,', third: ',third,', fourth: ',fourth)
#             dp[k][h] = max(first,max(second,max(third,fourth)))
#     return dp[n-1][n-1]
    
print(solution(3, [('W',2),('W',5),('W',1)], [('W',7),('W',8),('W',5)]))
print(solution(3, [('W',2),('W',5),('W',1)], [('L',7),('L',8),('L',4)]))
print(solution(2, [('W',6),('W',2)], [('L',8),('L',1)]))