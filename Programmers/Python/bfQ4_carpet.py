def solution(brown, yellow):
    hw = brown+yellow
    for h in range(3, hw):
        if hw%h==0 and hw/h+h==(brown+4)/2:
            return sorted([h,hw//h],reverse=True)

print(solution(10,2))
print(solution(8,1))
print(solution(24,24))
