def solution_fail(n, lost, reserve):
    lost = sorted(lost, reverse=True)
    reserve = sorted(reserve)
    for l in lost:
        if l in reserve:
            reserve.remove(l)
            lost.remove(l)
    print(reserve)
    print(lost)
    
    answer = n-len(lost)
    flag = len(reserve)-1
    for lo in lost:
        find = False
        while find==False and flag>=0:
            if reserve[flag] == lo-1 or reserve[flag] == lo or reserve[flag] == lo+1:
                answer+=1
                find=True
            flag-=1
    return answer

def solution(n, lost, reserve):
    lost = set(lost) # set() 자동 정렬 O, 연산 O
    reserve = set(reserve)
    
    losted = sorted(list(lost-reserve), reverse=True)
    reserved = sorted(list(reserve-lost))
    
    answer = n-len(losted)
    flag = len(reserved)-1
    for lo in losted:
        find = False
        while find==False and flag>=0:
            if reserved[flag] == lo-1 or reserved[flag] == lo or reserved[flag] == lo+1:
                answer+=1
                find=True
            flag-=1
        if find==False:
            flag = len(reserved)-1
    return answer


print(solution(13, [13, 6, 1], [11, 9, 8, 7])) # 11 <------ OK 헐. 끝나버리네. (38,39 X)
print()
print(solution(5, [2, 3, 5], [2, 3, 4])) # 4 <------ 5 아니냐
print(solution(7, [7, 4, 3, 5, 2, 1], [6, 5])) # 2 <----- 3 아니냐
print(solution(5,[2, 4],[1, 3, 5])) # 5
print(solution(4, [2], [1, 2])) # 4
print(solution(5,[2, 4],[3])) # 4
print(solution(4,[2, 3],[3, 4])) # 3
print(solution(6,[3,4,5],[3,4,6])) # 6
print(solution(5, [2, 4], [1, 3, 5])) # 5
print(solution(5, [2, 4], [3])) # 4
print(solution(3, [3], [1])) # 2
print(solution(4, [1, 3], [2, 4])) # 4
print(solution(5, [4, 2], [3, 5])) # 5
print(solution(5, [5, 3], [4, 2])) # 5
print(solution(5, [1], [5])) # 4
print(solution(10, [3, 4, 7, 9], [2, 3, 8])) # 8
print(solution(5, [2, 4], [5])) # 4
print(solution(5, [2, 3, 4], [3, 4, 5])) # 4
print(solution(5, [5, 3, 1], [2, 4])) # 4