def passing(idx, memo):
    if idx>0:
        memo[idx-1] = -1
    if idx<len(memo)-1:
        memo[idx+1] = -1

def back(idx, memo):
    if idx>0:
        if idx-2<0 or (idx-2>=0 and memo[idx-2]!=1):
            memo[idx-1] = 0
    if idx<len(memo)-1:
        if idx+2>len(memo)-1 or (idx+2<=len(memo)-1 and memo[idx+2]!=1):
            memo[idx+1] = 0
    
def re_selection(money, idx, memo, total, k):
    if idx>=len(money) or memo[idx]==-1 or memo[idx]==1:
        return 0

    memo[idx] = 1
    total+=money[idx]
    passing(idx, memo)
    print('>> memo: ',memo, ', total: ',total, ', k: ',k)
    
    result = total
    for i in range(idx+2, len(money)):
        if memo[i]==0:
            result = max(result, re_selection(money, i, memo, total, k+1))
            memo[i] = 0
            back(i, memo)
        
    return result
        
        
def solution(money):
    print('problem = ',money)
    max_sum = 0
    memo=[0]*len(money)
    for i in range(len(money)):
        max_sum = max(max_sum, re_selection(money, i, memo, 0, 0))
        memo[i] = 0
        back(i, memo)
    return max_sum
    

print(solution([1, 2, 3, 1]))