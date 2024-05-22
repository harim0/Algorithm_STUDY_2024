import heapq
import sys

input = sys.stdin.readline  # python 시간 초과 해결 백준 ㄱㅅㄹ
n, k = map(int, input().split())
jewries = [list(map(int, input().split())) for _ in range(n)]
bag_limit = [int(input()) for _ in range(k)]

jewries.sort()
bag_limit.sort()

answer = 0
my_bag = []
j = 0
for limit in bag_limit:
    while j<n and jewries[j][0]<=limit:
        heapq.heappush(my_bag, -jewries[j][1])
        j+=1
    if my_bag:
        answer-=heapq.heappop(my_bag)

print(answer)
