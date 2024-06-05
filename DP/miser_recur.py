def miser(np_list, m, unitp, k):
    if k==0:
        return 0
    else:
        result = miser(np_list, m, unitp, k-1)
        best = result+unitp
        for i in range(m):
            if k>=np_list[i][0]:
                result = miser(np_list, m, unitp, k-np_list[i][0])
                best = min(best, result+np_list[i][1])
        # print('k:',k,', i:',i,', best =',best)
        return best

def solution(np_list, m, unitp, k):
    best = miser(np_list, m, unitp, k)
    for i in range(k+1,200):
        print('\ti = ',i)
        best = min(best, miser(np_list, m, unitp, i))
    return best

def main(np_list, m, unitp, k_list):
    for k in k_list:
        print(solution(np_list, m, unitp, k))

main([(3,4.00),(2,2.50)],2,1.75,[1,4])