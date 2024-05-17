def solution_fail(name): # runtime Error
    answer, i=0
    alpha = 26
    prev_state = name[0]
    while i!=len(name):
        cnt = 0
        if name[i]=='A':    
            while name[i]=='A':
                cnt+=1
                prev_state = name[i]
                i+=1
            cnt+=1
            if cnt>0 and cnt<len(name)-cnt:
                answer+=cnt
            elif cnt>0:
                answer+=len(name)-cnt
        else: # A X
            if i>0 and prev_state!='A': # A X -> A X
                answer+=1
            if abs(ord(name[i])-ord('A'))<alpha//2:
                answer+=abs(ord(name[i])-ord('A'))
            else:
                answer+=abs(alpha-abs(ord(name[i])-ord('A')))
            prev_state = name[i]
            i+=1
    return answer

# print(solution("JEROEN"))
# print(solution("JAN"))
# print(solution("JAAAAON"))