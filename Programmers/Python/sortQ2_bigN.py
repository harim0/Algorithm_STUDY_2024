# 어렵다;

# def solution(numbers):
#     answer = ''
#     numbers = list(map(str, numbers))
#     num_list = []
#     while numbers:
#         num = numbers.pop()
#         if len(num)==1:
#             num_list.append((num*6,num))
#         elif len(num)==2:
#             num_list.append((num*3,num))
#         elif len(num)==3:
#             num_list.append((num*2,num))
#         else:
#             num_list.append((num,num))
#     num_list.sort()
#     while num_list:
#         answer+=num_list.pop()[1]
#     return str(int(answer))

def solution_fail(numbers):
    answer = ''
    numbers = list(map(str, numbers))
    num_list = []
    while numbers:
        num = numbers.pop()
        if len(num)==1:
            num_list.append((num*3,num))
        elif len(num)==2:
            if num[0]<num[1]:
                num_list.append((str(int(num+num[0])+1),num))
            else:
                num_list.append((num+num[0],num))
        else:
            num_list.append((num,num))
    num_list.sort()
    while num_list:
        answer+=num_list.pop()[1]
            
    return str(int(answer))
    
print(solution([110, 1])) 
print(solution([0,0,0,0])) # 0
print(solution([10, 104, 102])) # 10410210
print(solution([34,343])) # 34 343 
print(solution([3,30,34,5,9])) # 9 5 34 3 30
print(solution([979,97,978,81,818,817])) # 9799797881818817
print(solution([3,30,34,330,300,309,333,332,323])) # 34 333 3 332 330 323 309 30 300