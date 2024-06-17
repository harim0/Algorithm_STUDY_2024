total_calls = 0

def recur_pos(y, x, n, m, roadmap, answer):
    global total_calls
    total_calls+=1
    if x==m-1 and y==n-1:
        print("bingo :: ","(",x,",",y,")")
        answer+=1
        return 1
    if roadmap[y][x]==0:
        return 0
    else:
        print("(",x,",",y,")")
        paths = 0
        if y<n-1:
            paths+=recur_pos(y+1, x, n, m, roadmap, answer)
        if x<m-1:
            paths+=recur_pos(y, x+1, n, m, roadmap, answer)
        return paths

def re_solution(m, n, puddles):
    global total_calls
    total_calls = 0
    roadmap = [[0 if [i+1, j+1] in puddles else -1 for j in range(m)] for i in range(n)]
    answer = recur_pos(0, 0, n, m, roadmap, 0)
    print('total_calls = ',total_calls)
    return answer%1000000007

# print(re_solution(4,3,[[2, 2]]))
# print(re_solution(7,6,[[2, 2], [6, 6]]))


# def solution(m, n, puddles):
#     dp = [-1]*10001
#     answer = 0
    
#     return answer

# print(solution(4,3,[[2, 2]]))