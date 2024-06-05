def burger_miniar(m,n,b,memo):
    if memo[b]>=0:
        return memo[b]
    if b==0:
        memo[b] = 0
        return memo[b]
    if b>=m:
        first = burger_miniar(m,n,b-m,memo)
    else:
        first = -1
    if b>=n:
        second = burger_miniar(m,n,b-n,memo)
    else:
        second = -1
    if first==-1 and second==-1:
        return -1
    else:
        memo[b] = max(first, second)+1
        return memo[b]

def solution(m,n,b):
    memo=[-1]*(b+1)
    result = burger_miniar(m,n,b,memo)
    if result>-1:
        return result
    else:
        i = b-1
        result = burger_miniar(m,n,i,memo)
        while result==-1:
            i-=1
            result = burger_miniar(m,n,i,memo)
        return result
            
                
print(solution(4,9,22))
print(solution(4,9,54))
# print(solution(4,2,88))