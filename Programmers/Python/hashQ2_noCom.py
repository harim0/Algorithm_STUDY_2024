def solution(participant, completion):
    answer = ''
    set_part, set_comp = set(participant), set(completion)
    p_cnt, c_cnt = len(set_part), len(set_comp)
    
    if abs(p_cnt-c_cnt)==1:
        if p_cnt>c_cnt:
            answer = list(set_part-set_comp)[0]
        else:
            answer = list(set_comp-set_part)[0]
    else:
        participant.sort()
        completion.sort()
        while participant and completion:
            if participant[-1]==completion[-1]:
                participant.pop()
                completion.pop()
            elif participant[0]==completion[0]:
                participant.pop(0)
                completion.pop(0)
        if participant:
            answer = participant[0]
        else:
            answer = completion[0]
            
    return answer
    
print(solution(["leo", "kiki", "eden"],["eden", "kiki"]))
print(solution(["marina", "josipa", "nikola", "vinko", "filipa"],["josipa", "filipa", "marina", "nikola"]))
print(solution(["mislav", "stanko", "mislav", "ana"],["stanko", "ana", "mislav"]))