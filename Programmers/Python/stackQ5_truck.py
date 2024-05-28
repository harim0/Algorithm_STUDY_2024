# 본인이 약한 유형 DP

def solution(bridge_length, weight, truck_weights):
    answer = 0
    passingQ = []
    sum_trucks = 0
    
    while truck_weights or passingQ:
        answer+=1
        if passingQ and passingQ[0][1] == answer: # 건너감
            print('>> PASS Completed:', passingQ[0][0])
            sum_trucks-=passingQ[0][0]
            passingQ.pop(0)
        
        if truck_weights and sum_trucks+truck_weights[0]<=weight: # 건너도록
            truck = truck_weights.pop(0)
            print('>> FOR Passing:', truck)
            sum_trucks+=truck
            passingQ.append((truck, answer+bridge_length))
            
        print('truck_weights:', truck_weights)
        print('passingQ:', passingQ)
        print('sum_trucks:', sum_trucks)
        print(' answer:', answer)
        print()
    return answer

# print(solution(2,10,[7,4,5,6]))
# print(solution(100,100,[10]))
# print(solution(100,100,[10,10,10,10,10,10,10,10,10,10]))