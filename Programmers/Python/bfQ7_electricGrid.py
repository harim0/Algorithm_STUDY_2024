from collections import defaultdict

def bfs(node, graph, visited):
    cnt = 0
    stack = [node]
    while stack:
        cur_node = stack.pop()
        if not visited[cur_node]:
            visited[cur_node]=True
            cnt+=1
            for other_node in graph[cur_node]:
                if not visited[other_node]:
                    stack.append(other_node)
    return cnt

def solution(n, wires): 
    answer=98
    for i in range(len(wires)):
        graph=defaultdict(list)
        for j,(x,y) in enumerate(wires):
            if i==j:
                continue
            graph[x].append(y)
            graph[y].append(x)
        visited = [False]*(n+1)
        first_cnt = bfs(1, graph, visited)
        second_cnt = n-first_cnt
        if abs(second_cnt-first_cnt)<answer:
            answer = abs(second_cnt-first_cnt)
    return answer

print(solution(9,[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
print(solution(4,[[1,2],[2,3],[3,4]]))
print(solution(7,[[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]))