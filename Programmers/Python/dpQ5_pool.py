def dp(idx, n, memo, money, first):
    if idx>=n or (idx==n-1 and first):
        return 0
    ret = memo[first][idx]
    if ret!=-1:
        return ret
    if idx==0:
        first = 1
    ret = max(ret, money[idx]+dp(idx+2, n, memo, money, first))
    print('1 memo['+str(idx)+']['+str(first)+'] = ',ret)
    if idx == 0:
        first = 0
    ret = max(ret, dp(idx+1, n, memo, money, first))
    print('\t2 memo['+str(idx)+']['+str(first)+'] = ',ret)
    memo[first][idx] = ret
    return ret

def solution(money):
    print('problem = ',money)
    n = len(money)
    memo = [[-1] * n for _ in range(2)]
    answ = dp(0, n, memo, money, 0)
    print('memo = ',memo)
    return answ

print(solution([1, 2, 3, 1]))