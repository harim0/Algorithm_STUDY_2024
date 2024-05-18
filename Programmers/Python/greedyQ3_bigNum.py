def solution_fail(number, k):
    answer = ''
    if number[k]>max(list(number[:k])):
        answer = number[k:]
    else:
        number = list(number)
        i=0
        while i<len(number)-1:
            next_i = i+1
            if k==0:
                break
            elif k>0 and number[i]<number[next_i]:
                del number[i]
                k-=1
                i=0
            else:
                i+=1
        while k>0:
            number.pop()
            k-=1
        answer=''.join(map(str,number))
    return answer

# def solution(number, k):
#     answer = ''
#     i=0
#     li=[]
#     while i<len(number)-1:
#         next_i = i+1
#         if k==0:
#             break
#         elif k>0 and number[i]<number[next_i]:
#             li.append(i)
#             k-=1
#             i=0
#         else:
#             i+=1
#     for idx in range(len(number)):
#         if idx not in li:
#             answer+=number[idx]
#     while k>0:
#         answer = number[:len(number)-1]
#         k-=1
#     return answer

print(solution("98876543",3))
print(solution("413271234",4))
print(solution("1924",2))
print(solution("1231234",3))
print(solution("412345",3)) 
print(solution("4177252841",4)) # 작은 수부터 지우되 앞에 큰 수가 오도록