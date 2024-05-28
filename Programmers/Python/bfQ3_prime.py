memoization = set()
def check_prime(num):
    if num<=1:
        return 0
    elif num==2:
        return 1
    else:
        for i in range(2,int(num**0.5)+1):
            if num%i==0:
                return 0
        return 1

def possible_num(numbers, num, l, used):
    if len(num)==l:
        num_int = int(num)
        if num_int not in memoization:
            if check_prime(num_int):
                memoization.add(num_int)
                return 1
        return 0
    
    cnt = 0
    for idx in range(len(numbers)):
        if used[idx]:
            continue
        used[idx]=True
        cnt+=possible_num(numbers, num+numbers[idx], l, used)
        used[idx]=False
    return cnt

def solution(numbers):
    answer = 0
    for l in range(1,len(numbers)+1):
        answer+=possible_num(numbers,"",l,[0]*len(numbers))
    return answer

print(solution("17"))
print(solution("011"))
print(solution("121"))