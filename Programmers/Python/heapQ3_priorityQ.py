import heapq

def solution(operations):
    min_heap, max_heap = [], []
    syn_heap = {} 

    for op in operations:
        if op.startswith("I "):
            num = int(op[2:])
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, -num)
            if num in syn_heap:
                syn_heap[num] += 1
            else:
                syn_heap[num] = 1
        elif op == "D 1":  # 최대값 제거
            while max_heap and syn_heap[-max_heap[0]] == 0:
                heapq.heappop(max_heap)
            if max_heap:
                max_val = -heapq.heappop(max_heap)
                syn_heap[max_val] -= 1
        elif op == "D -1":  # 최소값 제거
            while min_heap and syn_heap[min_heap[0]] == 0:
                heapq.heappop(min_heap)
            if min_heap:
                min_val = heapq.heappop(min_heap)
                syn_heap[min_val] -= 1

    while max_heap and syn_heap[-max_heap[0]] == 0:
        heapq.heappop(max_heap)
    while min_heap and syn_heap[min_heap[0]] == 0:
        heapq.heappop(min_heap)
        
    if min_heap and max_heap:
        return [-max_heap[0], min_heap[0]]
    return [0, 0]

print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]))
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))
