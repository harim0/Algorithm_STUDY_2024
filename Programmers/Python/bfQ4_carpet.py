def solution(brown, yellow):
    hw = brown+yellow
    for h in range(3, hw):
        if hw%h==0 and hw/h+h==(brown+4)/2:
            return sorted([h,hw//h],reverse=True)

# import math # 근의 공식
# def solution(brown, yellow):
#     w = ((brown+4)/2 + math.sqrt(((brown+4)/2)**2-4*(brown+yellow)))/2
#     h = ((brown+4)/2 - math.sqrt(((brown+4)/2)**2-4*(brown+yellow)))/2
#     return [w,h]
xw

print(solution(10,2))
print(solution(8,1))
print(solution(24,24))
