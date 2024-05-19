def solution(number, k):
    answer=''
    stack = []
    
    for num in number:
        while k > 0 and stack and stack[-1] < num:
            stack.pop()
            k -= 1
        stack.append(num)
        
    if k > 0:
        stack = stack[:-k]
    answer = ''.join(stack)
    
    return answer


# print(solution("1924",2))
# print(solution("1231234",3))
# print(solution("98876543",3))
# print(solution("413271234",4)) # 작은 수부터 지우되 앞에 큰 수가 오도록
print(solution("9"*1000000, 999999))