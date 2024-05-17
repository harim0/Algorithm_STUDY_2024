def solution(name): 
    answer=0
    for char in name:
        answer+=min(ord(char)-ord('A'), 26-(ord(char)-ord('A')))
    print('answer:',answer)
    # 순방향+끝A 무시 or 순방향+역방향 중간A 무시
    maxA = -1
    Acnt = 0
    move = len(name)-1
    for i in range(len(name)):
        if name[i]=='A':
            Acnt+=1
        else:
            Acnt=0
        if maxA<Acnt:
            maxA=Acnt
            maxIdx=i
            move = min(move,abs((maxIdx-maxA)*2+1+(len(name)-1-(maxIdx+1))))
            print("move: ",move)
    print('maxA: ',maxA)
    print('maxIdx: ',maxIdx)
    if name[len(name)-1]=='A':
        print("len(name)-1-Acnt: ",len(name)-1-Acnt)
        move = min(move, len(name)-1-Acnt)
    answer+=move
    return answer

# 역방향 업데이트 고려 X ... 알파벳 만드는 횟수와 이동 횟수 분리
# print(solution("BBABAAAAAAB"))
# # print(solution("BBAB(3)AAAAAA(9)B")) # <-- 9? 11 아냐? // 4, 7(->3 <-4) // len=11 (A 6)
# print(solution("BBAAAAAAABAB")) 
# # print(solution("BB(1)AAAAAAA(8)BAB")) # <-- 9 // 4, 5(->1 <-4(2,2)) // len=12 (A 7)
# print(solution("BBAAAAABB"))
# # print(solution("BB(1)AAAAA(6)BB")) # <-- 8 // 4, 4(->1 <-3(2,1)) // len=9 (A 5)
# print()
# print(solution("BABBAABB")) 
# # print(solution("B(0)A(1)BBAABB")) # <-- 11 // 5, 6(<-) // len=8 (A 2)
# print(solution("BAAAAABAA")) # 5 // 2, 3(<-) // len=9 (A 5)
# print(solution("BBBABAABABABB")) # 20 // 8, 12(->) // len=13 (A 2)
# # print(solution("BAABBAAA")) # 7 // 3, 4(->) // len=8 (A 3)
print()
print(solution("AAAAAA")) # 0
print(solution("AAADAAA")) # 3+3= 6
print(solution("JEROEN")) # 56
print(solution("JAN")) # 23
print(solution("JAAAAON")) # 37 

# ABCDEFGHIJKLM
# NOPQRSTUVWXYZ ^^