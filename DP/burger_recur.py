# 2024-06-01
# 실패의 과정 # 3:55 - 4:30
# def recur(m, n, t, burger_cnt):
#     burger_cnt = 0
#     if t==0:
#         return burger_cnt
#     elif t-m==0: # 조건을 어떻게 설정해야?
#         return burger_cnt+1
#     elif t-n==0:
#         return burger_cnt+1
#     else:
#         recur(m,n,t-m,burger_cnt+1)
#         recur(m,n,t-n,burger_cnt+1)
#         recur(m,n,t-1,burger_cnt) # total==t인 경우가 불가능 시

# 교재 : 알고리듬으로 생각하기 :: 첫번째 해답

total_calls = 0
def solve_t(m, n, t):
    global total_calls
    total_calls+=1
    if t==0:
        return 0
    if t>=m:
        first = solve_t(m, n, t-m)
    else:
        first = -1
    if t>=n:
        second = solve_t(m, n, t-n)
    else:
        second = -1
    if first==-1 and second==-1:
        return -1
    else:
        return max(first, second)+1


def solution(m, n, t):
    global total_calls
    total_calls = 0
    result = solve_t(m, n, t)
    if result>0:
        print('total_calls:', total_calls)
        return result
    else:
        i = t-1
        result = solve_t(m, n, i)
        while result==-1:
            i-=1
            result = solve_t(m, n, i)
        print('total_calls:', total_calls)
        return (result, t-i)
            
print(solution(4,9,22))
print(solution(4,9,54))
# print(solution(4,9,15))
# print(solution(4,3,88))
# print(solution(4,2,88))