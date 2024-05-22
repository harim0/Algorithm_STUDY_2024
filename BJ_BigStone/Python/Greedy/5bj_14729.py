import heapq
import sys

def print_score(i):
    if i!=0:
        num = heapq.heappop(scores)
        print_score(i-1)
        print(f"{-num:.3f}")

input = sys.stdin.readline 
n = int(input())
scores = []
for _ in range(n):
    num = float(input())
    heapq.heappush(scores,-num)
    if len(scores)>7:
        heapq.heappop(scores)

print_score(len(scores))
