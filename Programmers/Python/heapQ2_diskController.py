import heapq

def solution(jobs): 
    time = 0
    answer = 0
    n = len(jobs)
    heapq.heapify(jobs) # req_time 순
    print('heapify => ', jobs)
    
    while jobs:
        req_time, job_time=heapq.heappop(jobs)
        time+=(abs(req_time-time)+job_time)
        # if req_time>=time:
        #     time = req_time+job_time
        answer+=time
        
        scheduler = []
        while jobs and answer>jobs[0][0]: # 작업 중 요청된 작업들 job_time 순
            req_time, job_time=heapq.heappop(jobs)
            heapq.heappush(scheduler,(job_time, req_time))
        print('heap => ', scheduler)
        while scheduler:
            job_time, req_time=heapq.heappop(scheduler)
            answer+=(abs(time-req_time)+job_time)
            time+=job_time
    answer=int(answer/n)
        
    return answer

print(solution([[0, 3], [1, 9], [2, 6]])) # (3+(6+1)+(9+8))/3 = 27/3 = 9
print(solution([[0, 9], [1, 1], [1, 1], [1, 1], [1, 1]])) # (9+(1+8)+(1+9)+(1+10)+(1+11)) = 51/5 = 10