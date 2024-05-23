import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while len(scoville)>1 and scoville[0]<K:
        first = heapq.heappop(scoville)
        if len(scoville)==0:
            return -1  
        second = heapq.heappop(scoville)
        new = first + second * 2
        heapq.heappush(scoville, new)
        answer += 1
    
    if scoville[0]<K:
        return -1 
    return answer

print(solution([1, 2, 3, 9, 10, 12], 7))
