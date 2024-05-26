import heapq

def solution(jobs): 
    time = 0
    answer = 0
    n = len(jobs)
    heapq.heapify(jobs) # req_time 순
    # print('heapify => ', jobs)
    
    ready_queue = []
    while jobs or ready_queue:
        while jobs and time>=jobs[0][0]:  # 작업 중 요청된 작업들 :: job_time 순
            req_time, job_time=heapq.heappop(jobs)
            heapq.heappush(ready_queue,(job_time, req_time))
            
        if ready_queue: 
            job_time, req_time=heapq.heappop(ready_queue)
            time+=job_time 
            answer+=time-req_time
        else: 
            time = jobs[0][0]
        
    return answer//n

print(solution([[0, 10], [4, 10], [15, 2], [5, 11]])) # 15
print(solution([[24, 10], [28, 39], [43, 20], [37, 5], [47, 22], [20, 47], [15, 34], [15, 2], [35, 43], [26, 1]])) # 72
print(solution([[1, 4], [7, 9], [1000, 3]])) # 5
print(solution([[7, 8], [3, 5], [9, 6]])) # 9
print(solution([[0, 3], [10, 1]])) # 2
print(solution([[0, 3], [4, 4], [5, 3], [7, 1]])) # 4
print(solution([[0, 3], [1, 9], [2, 6]])) # (3+(6+1)+(9+8))/3 = 27/3 = 9
print(solution([[0, 9], [1, 1], [1, 1], [1, 1], [1, 1]])) # (9+(1+8)+(1+9)+(1+10)+(1+11)) = 51/5 = 10