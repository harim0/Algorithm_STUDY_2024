INF = 9**8

def recur_N(N, number, pnum, k):
    if pnum==number:
        return k+1
    if k>=7:
        return -1
    
    # print('pnum : ',pnum, ', k=',k)
    results = []
    if pnum!=0:
        res = recur_N(N, number, pnum*N, k+1)
        if res!=-1:
            results.append(res)
        res = recur_N(N, number, pnum//N, k+1)
        if res!=-1:
            results.append(res)
        res = recur_N(N, number, pnum-N, k+1)
        if res!=-1:
            results.append(res)
    res = recur_N(N, number, pnum+N, k+1)
    if res!=-1:
            results.append(res)
    res = recur_N(N, number, int(str(pnum)+str(N)), k+1)
    if res!=-1:
            results.append(res)
            
    if not results:
        return -1
    else:
        return min(results)

def solution(N, number):
    return recur_N(N, number, N, 0)

print(solution(5,12)) # 4
print(solution(2,11)) # 3