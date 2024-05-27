def solution(citations):
    citations.sort()
    n = len(citations)
    
    for i in range(n):
        h_idx = n - i
        if citations[i] >= h_idx:
            return h_idx
    
    return 0

print(solution([4,4,4,4,4])) # 
print(solution([0,0,0,10000,10000,10000,10000])) # 4
print(solution([0,0,0,0])) # 
print(solution([0, 1, 3, 5, 6])) # 
print(solution([10, 8, 5, 4, 3])) # 
print(solution([25, 8, 5, 3, 3])) # 