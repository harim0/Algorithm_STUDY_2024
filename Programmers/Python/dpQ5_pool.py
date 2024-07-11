def dp(n, money):
    if n==0:
        return money[0]
    if n==1:
        return max(money[0], money[1])
    dp_table = [0]*n
    dp_table[0] = money[0]
    dp_table[1] = max(money[0], money[1])
    
    for i in range(2, n):
        dp_table[i] = max(dp_table[i-1], money[i]+dp_table[i-2])
    return dp_table[n-1]

def solution(money):
    n = len(money)
    if n==1:
        return money[0]
    return max(dp(n-1, money[:-1]), dp(n-1, money[1:]))

print(solution([1, 2, 3, 1]))