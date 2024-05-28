def solution(answers):
    std_answers = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    result = []
    for std_answer in std_answers:
        std_answer*=((len(answers)//len(std_answer))+1)
    
    std_corrects = [0,0,0]
    for i in range(len(answers)):
        if std_answers[0][i]==answers[i]:
            std_corrects[0]+=1
        if std_answers[1][i]==answers[i]:
            std_corrects[1]+=1
        if std_answers[2][i]==answers[i]:
            std_corrects[2]+=1
    
    for idx, s in enumerate(std_corrects):
        if s == max(std_corrects):
            result.append(idx+1)
            
    return result
    

print(solution([1,2,3,4,5]))
print(solution([1,3,2,4,2]))