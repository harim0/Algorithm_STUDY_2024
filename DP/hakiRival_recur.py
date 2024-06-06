def haki_rival(k_rst, h_rst, k, h):
    if k==-1 or h==-1:
        return 0
    global total_calls 
    total_calls += 1
    if (k_rst[k][0]=='W' and h_rst[h][0]=='L' and k_rst[k][1]>h_rst[h][1]) or\
    (k_rst[k][0]=='L' and h_rst[h][0]=='W' and k_rst[k][1]<h_rst[h][1]):
        first = haki_rival(k_rst, h_rst, k-1, h-1)+k_rst[k][1]+h_rst[h][1]
    else:
        first = 0
    second = haki_rival(k_rst, h_rst, k, h-1)
    third = haki_rival(k_rst, h_rst, k-1, h)
    fourth = haki_rival(k_rst, h_rst, k-1, h-1)
    # print('first: ',first,', second: ',second,', third: ',third,', fourth: ',fourth)
    return max(first,max(second,max(third,fourth)))
    
def solution(n, k_rst, h_rst):
    global total_calls 
    total_calls = 0
    result = haki_rival(k_rst, h_rst, n-1, n-1)
    print('=> ',result, ', total_calls: ',total_calls)
    
solution(3, [('W',2),('W',5),('W',1)], [('W',7),('W',8),('W',5)])
solution(3, [('W',2),('W',5),('W',1)], [('L',7),('L',8),('L',4)])
solution(2, [('W',6),('W',2)], [('L',8),('L',1)])