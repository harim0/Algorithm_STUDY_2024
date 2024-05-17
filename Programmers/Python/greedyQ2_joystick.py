def solution(name): 
    print(name, 'len = ',len(name))
    answer=0
    for char in name:
        answer+=min(ord(char)-ord('A'), 26-(ord(char)-ord('A')))
    print('alphabet_transform:',answer)
    # 순방향+끝A 무시 or 순방향+역방향 중간A 무시
    move = len(name)-1
    for i in range(len(name)):
        next_i = i+1
        while next_i<len(name) and name[next_i]=='A':
            next_i+=1
        print('i: ',i,", next_i: ",next_i,", move: ",i+len(name)-next_i+min(i,len(name)-next_i))
        move = min(move,i+len(name)-next_i+min(i,len(name)-next_i))
    answer+=move
    return answer


# 역방향 업데이트 고려 X ... 알파벳 만드는 횟수와 이동 횟수 분리
print(solution("BBABAAAAAAB")) # <--- 역방향 먼저 이동 1(n-next_i)+1(n-next_i)+3(i)
# print(solution("BBAB(3)AAAAAA(9)B")) # <-- *** 9? 11 아냐? // 4, 7(->3 <-4) // len=11 (A 6)
print()
print(solution("BBAAAAAAABAB")) 
# print(solution("BB(1)AAAAAAA(8)BAB")) # <-- 9 // 4, 5(->1 <-4(2,2)) // len=12 (A 7)
print(solution("BBAAAAABB"))
# print(solution("BB(1)AAAAA(6)BB")) # <-- 8 // 4, 4(->1 <-3(2,1)) // len=9 (A 5)
print()
print(solution("BABBAABB")) 
# print(solution("B(0)A(1)BBAABB")) # <-- 11 // 5, 6(<-) // len=8 (A 2)
print(solution("BAAAAABAA")) # 5 // 2, 3(<-) // len=9 (A 5)
print(solution("BBBABAABABABB")) # 20 // 8, 12(->) // len=13 (A 2)
# print(solution("BAABBAAA")) # 7 // 3, 4(->) // len=8 (A 3)
print()
print(solution("AAAAAA")) # 0
print(solution("AAADAAA")) # 3+3= 6
print(solution("JEROEN")) # 56
print(solution("JAN")) # 23
print(solution("JAAAAON")) # 36

# ABCDEFGHIJKLM
# NOPQRSTUVWXYZ ^^