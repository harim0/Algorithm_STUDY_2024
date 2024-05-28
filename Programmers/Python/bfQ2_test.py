def solution(answers):
    std_answers = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    result = []
    for std_answer in std_answers:
        std_answer*=((len(answers)//len(std_answer))+1)
    
    std_corrects = [[0,0],[0,1],[0,2]]
    for i in range(len(answers)):
        if std_answers[0][i]==answers[i]:
            std_corrects[0][0]+=1
        if std_answers[1][i]==answers[i]:
            std_corrects[1][0]+=1
        if std_answers[2][i]==answers[i]:
            std_corrects[2][0]+=1
    std_corrects.sort()
    
    if std_corrects[2][0]==std_corrects[0][0]==std_corrects[1][0]:
        return [1,2,3]
    elif std_corrects[2][0]==std_corrects[1][0]:
        first = std_corrects[2][1]+1
        second = std_corrects[1][1]+1
        return sorted([first, second])
    else:
        num = std_corrects[2][1]+1
        return [num]
    

print(solution([1,2,3,4,5]))
print(solution([1,3,2,4,2]))