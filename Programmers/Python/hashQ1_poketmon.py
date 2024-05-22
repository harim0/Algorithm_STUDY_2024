def solution(nums):
    answer = 0
    if len(set(nums))<=len(nums)//2:
        answer = len(set(nums))
    else:
        answer=len(nums)//2
    return answer

print(solution([3,1,2,3])) # 3 , 2
print(solution([3,3,3,2,2,4])) # 3 , 3
print(solution([3,3,3,2,2,2])) # 2 , 3
print(solution([1,3,2,4,5,6])) # 6 , 3