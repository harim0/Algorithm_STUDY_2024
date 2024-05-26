def solution(array, commands):
    answer = []
    for command in commands:
        tmp = []
        for i in range(command[0]-1, command[1]):
            tmp.append(array[i])
        tmp.sort()
        answer.append(tmp[command[2]-1])
    return answer

print(solution([1, 5, 2, 6, 3, 7, 4],[[2, 5, 3], [4, 4, 1], [1, 7, 3]]))