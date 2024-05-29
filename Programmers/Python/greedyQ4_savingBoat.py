def solution(people, limit):
    answer = 0
    n = len(people)
    people.sort()
    
    initial_w = people[0]
    for i in range(1,n):
        initial_w+=people[i]
        if initial_w>limit:
            answer+=1
            initial_w=people[i]
        if initial_w and i==n-1:
            return answer+1
    return answer
            

print(solution([70, 50, 80, 50], 100)) # 3
print(solution([20, 60, 70, 80, 30], 100)) # 3
print(solution([70, 80, 50], 100)) # 3
print(solution([70, 80, 50, 50, 100, 90, 20, 20, 20, 30], 100)) # 6