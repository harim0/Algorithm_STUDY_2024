import heapq # heap으로 최소 최대값 어떻게 Delete?

def solution(operations):
    answer = []
    result = []
    
    for op in operations:
        if op[0]=='I':
            answer.append(int(op[2:]))
        else:
            if answer:
                answer.sort()
                if op=="D -1":
                    answer.pop(0)
                elif op=="D 1":
                    answer.pop()
    if answer:
        answer.sort()
        result.append(answer[-1])
        result.append(answer[0])
    else:
        result.append(0)
        result.append(0)
        
    return result

print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]))
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))