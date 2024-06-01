# BF 1차 = 2:30-3:30 집중해보자 2차 = 4:40-5:20 + 5:30-6:02
# 변수 간 관계를 명확히 해보자 => l : tree 높이(선택 횟수)

def recur(idx, triangle, store, l, sum_value, sum_list):
    if len(store)==len(triangle):
        return
    print('recur| idx:',idx,', store:',store,', l:',l)
    print('\t\t\t\ttriangle[',len(store),'][',idx,']:',triangle[len(store)][idx])
    print('\t\t\t\t:::',triangle[len(store)])
    value = triangle[len(store)][idx]
    store.append(value)
    sum_value+=value
    if len(store)==len(triangle):
        sum_list.append(sum_value)
    recur(idx, triangle, store, l+1, sum_value, sum_list)
    store.pop()
    sum_value-=value
    if idx<len(triangle[len(store)])-1:
        print('\t\t\t\t> triangle[',len(store),'][',idx,']:',triangle[len(store)][idx+1])
        value = triangle[len(store)][idx+1]
        store.append(value)
        sum_value+=value
        if len(store)==len(triangle):
            sum_list.append(sum_value)
        recur(idx+1, triangle, store, l+1, sum_value, sum_list)
        store.pop()
        sum_value-=value

def solution(triangle):
    sum_list = []
    recur(0,triangle,[],0,0,sum_list)
    print(sum_list)
    return max(sum_list)


print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))