n = int(input())

meetings = []
for _ in range(n):
    x, y = map(int, input().split())
    meetings.append((x,y))
meetings.sort(key=lambda meetings : (meetings[1], meetings[0])) # 하나로만 설정했을 때의 문제

answer = 0
top = 0
for meet in meetings:
    if top<=meet[0]:
        answer+=1
        top=meet[1]
        
print(answer)
    