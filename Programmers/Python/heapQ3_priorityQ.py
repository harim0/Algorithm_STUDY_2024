import heapq 

def solution(operations):
    max_heap = []
    min_heap = []
    answer = []
    
    for op in operations:
        # print("op =>",op)
        if op[0]=='I':
            heapq.heappush(min_heap, int(op[2:]))
            heapq.heappush(max_heap, -int(op[2:]))
        else:
            if min_heap and max_heap:
                if len(min_heap)==1 or len(max_heap)==1 or -max_heap[0]<min_heap[0]:
                    min_heap=[]
                    max_heap=[]
                elif min_heap and op=="D -1": # 최소값
                    heapq.heappop(min_heap)
                elif max_heap and op=="D 1": # 최대값
                    heapq.heappop(max_heap)
        # print("min_heap:",min_heap)
        # print("max_heap:",max_heap)
        # print()
    if min_heap and max_heap:
        answer.append(-max_heap[0])
        answer.append(min_heap[0])
    else:
        answer.append(0)
        answer.append(0)
        
    return answer

print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]))
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))