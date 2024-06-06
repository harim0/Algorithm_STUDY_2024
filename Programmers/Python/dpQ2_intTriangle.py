# 2차 = DP 2024-06-06 5min (= DP/Skii_dp.py)
def solution(triangle):
    n = len(triangle)
    dp = [[0]*n for _ in range(n)]
    
    for init in range(n):
        dp[n-1][init] = triangle[n-1][init]
    
    for i in range(n-2,-1,-1):
        for j in range(i+1):
            dp[i][j] = triangle[i][j]+max(dp[i+1][j], dp[i+1][j+1])
    return dp[0][0]


print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))


# BF 1차 = 2024-05-30 2:30-3:30 집중해보자 2차 = 4:40-5:20 + 5:30-6:02
# 변수 간 관계를 명확히 해보자 => l : tree 높이(선택 횟수)

# def recur(idx, triangle, store, l, sum_value, sum_list):
#     if len(store)==len(triangle):
#         return
#     value = triangle[len(store)][idx]
#     store.append(value)
#     sum_value+=value
#     if len(store)==len(triangle):
#         sum_list.append(sum_value)
#     recur(idx, triangle, store, l+1, sum_value, sum_list)
#     store.pop()
#     sum_value-=value
#     if idx<len(triangle[len(store)])-1:
#         print('\t\t\t\t> triangle[',len(store),'][',idx,']:',triangle[len(store)][idx+1])
#         value = triangle[len(store)][idx+1]
#         store.append(value)
#         sum_value+=value
#         if len(store)==len(triangle):
#             sum_list.append(sum_value)
#         recur(idx+1, triangle, store, l+1, sum_value, sum_list)
#         store.pop()
#         sum_value-=value