# 고심이 -> TWO POINTER with GPT
def solution(people, limit):
    answer = 0
    people.sort()
    start, end = 0, len(people)-1
    
    while start<=end:
        if people[start]+people[end]<=limit:
            start += 1
        end -= 1
        answer += 1

    return answer
            

print(solution([70, 50, 80, 50], 100)) # 50 50 70 80 => 3
print(solution([20, 60, 70, 80, 30], 100)) # 20 30 60 70 80 => 3
print(solution([70, 80, 50], 100)) # 50 70 80 => 3