import heapq

def solution(jobs): 
    time = 0
    answer = 0
    n = len(jobs)
    heapq.heapify(jobs) # req_time 순
    # print('heapify => ', jobs)
    
    while jobs:
        if time<=jobs[0][0]: # 작업 X (req_time >= time) :: req_time 순
            req_time, job_time=heapq.heappop(jobs)
            # print('pop: (',req_time,',',job_time,')')
            answer+=job_time 
            time+=abs(req_time-time)+job_time
            # print('\t\ttime:',time)
        else: # 작업 중 요청된 작업들 :: job_time 순
            scheduler = []
            while jobs and time>jobs[0][0]: 
                req_time, job_time=heapq.heappop(jobs)
                heapq.heappush(scheduler,(job_time, req_time))
            # print('heap => ', scheduler)
            while scheduler:
                job_time, req_time=heapq.heappop(scheduler)
                answer+=abs(time-req_time)+job_time
                time+=job_time
                # print('\t\ttime:',time)
    answer=int(answer/n)
        
    return answer

print(solution([[1, 4], [7, 9], [1000, 3]])) # 5
print(solution([[7, 8], [3, 5], [9, 6]])) # 9
print(solution([[0, 3], [10, 1]])) # 2
print(solution([[0, 3], [4, 4], [5, 3], [7, 1]])) # 4
print(solution([[0, 3], [1, 9], [2, 6]])) # (3+(6+1)+(9+8))/3 = 27/3 = 9
print(solution([[0, 9], [1, 1], [1, 1], [1, 1], [1, 1]])) # (9+(1+8)+(1+9)+(1+10)+(1+11)) = 51/5 = 10