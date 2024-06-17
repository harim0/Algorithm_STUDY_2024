total_calls = 0

# def recur_pos(y, x, n, m, roadmap, answer):
#     if x==m-1 and y==n-1:
#         return 1
#     paths = 0
#     if y<n-1 and roadmap[y+1][x]!=0:
#         paths+=recur_pos(y+1, x, n, m, roadmap, answer)%1000000007
#     if x<m-1 and roadmap[y][x+1]!=0:
#         paths+=recur_pos(y, x+1, n, m, roadmap, answer)%1000000007
#     return paths

def memo_pos(y, x, n, m, roadmap, answer, memo):
    if x==m-1 and y==n-1:
        return 1
    if memo[y][x] != -1:
        return memo[y][x]
    global total_calls
    total_calls+=1
    paths = 0
    if y<n-1 and roadmap[y+1][x]!=0:
        paths+=memo_pos(y+1, x, n, m, roadmap, answer, memo)%1000000007
    if x<m-1 and roadmap[y][x+1]!=0:
        paths+=memo_pos(y, x+1, n, m, roadmap, answer, memo)%1000000007
    memo[y][x] = paths
    return  memo[y][x]


def solution(m, n, puddles):
    global total_calls
    total_calls = 0
    puddles = set((pu[1]-1, pu[0]-1) for pu in puddles)
    roadmap = [[0 if (i, j) in puddles else -1 for j in range(m)] for i in range(n)]
    memo = [[-1 for _ in range(m)] for _ in range(n)]
    answer = memo_pos(0, 0, n, m, roadmap, 0, memo)
    print('total_calls: ',total_calls)
    return answer

print(solution(4,3,[[2, 2]]))
print(solution(7,6,[[2, 2], [6, 6]]))
