def getroot(n, parent):
    if parent[n]!=n:
        parent[n]=getroot(parent[n], parent)
    return parent[n]

def isSameParent(x, y, parent):
    return getroot(x, parent)==getroot(y, parent)

def unionParent(x, y, parent):
    x = getroot(x, parent)
    y = getroot(y, parent)
    if x<y:
        parent[y] = x
    else:
        parent[x] = y
    
def minDisKruskal(n, graph):
    sum = 0
    edges_used = 0
    parent = [i for i in range(n)]
    for u,v,cost in graph:
        if not isSameParent(u, v, parent):
            sum+=cost
            unionParent(u,v,parent)
            edges_used+=1
            if edges_used==n-1:
                break
    return sum
    
def solution(n, costs):
    costs.sort(key=lambda x : x[2])
    answer = minDisKruskal(n, costs)
    return answer

# print(solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]])) # 4
# print(solution(5, [[0, 1, 5], [1, 2, 3], [2, 3, 3], [3, 1, 2], [3, 0, 4], [2, 4, 6], [4, 0, 7]])) # 15
print(solution(5, [[0, 1, 1], [3, 4, 1], [1, 2, 2], [2, 3, 4]])) # 8
print(solution(4, [[0, 1, 5], [1, 2, 3], [2, 3, 3], [1, 3, 2], [0, 3, 4]])) # 9
print(solution(5, [[0, 1, 1], [3, 1, 1], [0, 2, 2], [0, 3, 2], [0, 4, 100]])) # 104
print(solution(6, [[0, 1, 5], [0, 3, 2], [0, 4, 3], [1, 4, 1], [3, 4, 10], [1, 2, 2], [2, 5, 3], [4, 5, 4]] )) # 11
print(solution(5, [[0, 1, 1], [2, 3, 1], [3, 4, 2], [1, 2, 2], [0, 4, 100]]))# 6
print(solution(5, [[0, 1, 1], [0, 4, 5], [2, 4, 1], [2, 3, 1], [3, 4, 1]]))# 8
print(solution(5, [[0, 1, 1], [0, 2, 2], [0, 3, 3], [0, 4, 4], [1, 3, 1]]))# 8