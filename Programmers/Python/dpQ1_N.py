answ = -1

def recur_N(N, number, pnum, k, s):
    global answ
    if k>8:
        return
    if pnum==number:
        if k<answ or answ==-1:
            print('s: ',s,'\t, k='+str(k), ', pnum=',pnum)
            answ = k
        return
    
    NN = 0
    for i in range(8):
        NN = NN*10+N
        recur_N(N, number, pnum+NN, k+i+1, s+' + '+str(NN))
        recur_N(N, number, pnum-NN, k+i+1, s+' - '+str(NN))
        recur_N(N, number, pnum*NN, k+i+1, s+' * '+str(NN))
        recur_N(N, number, pnum//NN, k+i+1, s+' / '+str(NN))

def solution(N, number):
    global answ
    answ = -1 
    recur_N(N, number, 0, 0, '')
    return answ

# print(solution(5,12)) # 4
# print(solution(2,11)) # 3
# print(solution(1,121)) # 4
print(solution(8,53)) # 5
# print(solution(5,3025)) # 4 
# print(solution(5,3125)) # 5


# def recur_N(N, number, pnum, k, memo):
#     if pnum==number:
#         return k+1
#     if k>=7:
#         return -1
#     if (pnum,k) in memo:
#         return memo[(pnum,k)]
    
#     results = []
#     if pnum!=0:
#         res = recur_N(N, number, pnum*N, k+1, memo)
#         if res!=-1:
#             results.append(res)
#         res = recur_N(N, number, pnum//N, k+1, memo)
#         if res!=-1:
#             results.append(res)
#         res = recur_N(N, number, pnum-N, k+1, memo)
#         if res!=-1:
#             results.append(res)
#     res = recur_N(N, number, pnum+N, k+1, memo)
#     if res!=-1:
#             results.append(res)
#     res = recur_N(N, number, int(str(pnum)+str(N)), k+1, memo)
#     if res!=-1:
#             results.append(res)
            
#     if not results:
#         memo[(pnum,k)] = -1
#     else:
#         memo[(pnum,k)] = min(results)
#     return memo[(pnum,k)]

# def solution(N, number):
#     memo = {}
#     return recur_N(N, number, N, 0, memo)