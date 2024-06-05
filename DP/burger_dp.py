def solution(m,n,b):
    dp=[-1]*(b+1)
    dp[0] = 0
    for i in range(1,b+1):
        if i>=m:
            first = dp[i-m]
        else:
            first = -1
        if i>=n:
            second = dp[i-n]
        else:
            second = -1
        if first==-1 and second==-1:
            dp[i] = -1
        else:
            dp[i] = max(first, second)+1
        # print("dp[",i,"]=",dp[i])
    if dp[b]>-1:
        return dp[b]
    else:
        i = b-1
        while dp[i]==-1:
            i-=1
        return (dp[b],b-i)
                
print(solution(4,9,22))
print(solution(4,9,54))