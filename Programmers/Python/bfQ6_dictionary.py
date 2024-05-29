
def solution(word):
    answer = 0
    vowel = {'A': 1, 'E': 2, 'I': 3, 'O': 4, 'U': 5}    
    pattern = [sum(pow(5,i) for i in range(j+1)) for j in range(5)]
    for i,char in enumerate(word):
        answer+=(pattern[4-i]*(vowel[char]-1)+1)
    return answer

print(solution("AAAAE"))
print(solution("AAAE"))
print(solution("I"))
print(solution("EIO"))
