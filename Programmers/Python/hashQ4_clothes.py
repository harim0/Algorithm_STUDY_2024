def numOfcases(hash_map, k):
    result = 0
    
    def recur_cal(s, mult, cnt):
        nonlocal result
        if cnt==k:
            result+=mult
            return
        for i in range(s, len(hash_map)):
            recur_cal(i+1, mult * hash_map[i], cnt+1)
            
    recur_cal(0, 1, 0)
    return result

def solution(clothes):
    answer = 0
    hash_map = {}
    cloth_types = {}
    
    for cloth in clothes:
        cloth_type = cloth[1]
        if cloth_type not in cloth_types:
            idx = len(cloth_types)
            cloth_types[cloth_type]=idx
            hash_map[idx]=1
        else:
            hash_map[cloth_types[cloth_type]]+=1
    
    for i in range(len(hash_map),0,-1):
        answer+=numOfcases(hash_map,i)
        
    return answer

print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
print(solution([["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]))