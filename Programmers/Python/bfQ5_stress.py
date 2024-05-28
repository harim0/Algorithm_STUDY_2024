def choose_dungeons(k, dungeons, used, cnt):
    max_cnt = cnt
    for idx in range(len(dungeons)):
        if not used[idx] and k>=dungeons[idx][0]:
            used[idx] = True
            max_cnt = max(max_cnt, choose_dungeons(k-dungeons[idx][1], dungeons, used, cnt+1))
            used[idx] = False
    return max_cnt

def solution(k, dungeons):
    answer = choose_dungeons(k, dungeons, [False] * len(dungeons), 0)
    return answer

print(solution(80, [[80, 20], [50, 40], [30, 10]]))
