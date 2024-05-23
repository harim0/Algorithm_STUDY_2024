import heapq

def solution(scoville, K):
    answer = 0
    scoville.sort()
    while(1):
        first = heapq.heappop(scoville)
        second = heapq.heappop(scoville)
        new = first+second*2
        heapq.heappush(scoville, new)
        answer+=1
        
        check = True
        for scovil in scoville:
            if scovil<K:
                check = False
                break
        if check==True:
            return answer

print(solution([1, 2, 3, 9, 10, 12], 7))