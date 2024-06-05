def miser(np_list, m, unitp, k, memo):
    if memo[k]>=0:
        return memo[k]
    if k==0:
        memo[k] = 0
        return memo[k]
    else:
        result = miser(np_list, m, unitp, k-1, memo)
        best = result+unitp
        for i in range(m):
            if k>=np_list[i][0]:
                result = miser(np_list, m, unitp, k-np_list[i][0], memo)
                best = min(best, result+np_list[i][1])
            # print('i:',i,', best=',best)
        memo[k] = best
        return memo[k]

def solution(np_list, m, unitp, k, memo):
    best = miser(np_list, m, unitp, k, memo)
    for i in range(k+1,200):
        best = min(best, miser(np_list, m, unitp, i, memo))
    return best

def main(np_list, m, unitp, k_list):
    memo = [-1]*201
    for k in k_list:
        print(solution(np_list, m, unitp, k, memo))

main([(3,4.00),(2,2.50)],2,1.75,[1,4])