# FOR 최댓값, 큰 + 큰 / 큰 - 작 <- min_val과 max_val을 어떻게 쓸 것인지

INF = 100000000

def re_cal(arr, start, end, memo, ismax):
    if (start, end, ismax) in memo:
        return memo[(start, end, ismax)]
    if start==end-1:
        memo[(start, end, 0)] = int(arr[start])
        memo[(start, end, 1)] = int(arr[start])
        return int(arr[start])
    min_val = INF
    max_val = -INF
    # print('start: ',start,', end: ',end, 'arr: ',arr[start:end])
    for i in range(start, end):
        if arr[i]=='+':
            min_val = min(min_val, re_cal(arr, start, i, memo, 0)+re_cal(arr, i+1, end, memo, 0))
            max_val = max(max_val, re_cal(arr, start, i, memo, 1)+re_cal(arr, i+1, end, memo, 1))
            # print('val: ',max_val)
        if arr[i]=='-':
            min_val = min(min_val, re_cal(arr, start, i, memo, 0)-re_cal(arr, i+1, end, memo, 1))
            # print('min_val: ',min_val)
            max_val = max(max_val, re_cal(arr, start, i, memo, 1)-re_cal(arr, i+1, end, memo, 0))
            # print('max_val: ',max_val)
    memo[(start, end, 1)] = max_val
    memo[(start, end, 0)] = min_val
    if ismax:
        return max_val
    else:
        return min_val
    
def solution(arr):
    memo = {}
    return re_cal(arr, 0, len(arr), memo, 1)

print(solution(["1", "-", "3", "+", "5", "-", "8"])) # 1
print(solution(["5", "-", "3", "+", "1", "+", "2", "-", "4"])) # 3