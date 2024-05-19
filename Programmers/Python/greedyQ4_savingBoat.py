def solution(people, limit):
    answer = 0
    people = sorted(people)
    # print('*** people: ',people)
    i = 0
    while i<len(people):
        people_cnt = 0
        boat_weight = 0
        next_i = i
        # print('next_i:',next_i)
        while next_i<len(people):
            boat_weight+=people[next_i] # 140, # 0-4, 4
            people_cnt+=1
            if boat_weight>=limit:
                break
            next_i+=1
        # print('next_i:',next_i)
        # print('people_cnt:',people_cnt)
        if boat_weight==limit: # 초기화
            i=next_i+1
            answer+=1
            boat_weight = 0
            people_cnt = 0
            # print("boat_weight==limit")
        else: # boat_weight>limit -> 넘치는 것 VS 부족한 것
            if next_i>=len(people)-1:
                # print("next_i>=len(people)-1")
                break
            candidate_i = next_i # 4
            candidate_weight = 0
            candidate_people_cnt = 0
            while candidate_i<len(people):
                candidate_weight+=people[candidate_i]  # 100, # 4-5
                candidate_people_cnt+=1
                if candidate_weight>=limit:
                    break
                candidate_i+=1 # 5
            # print('next_i: ',next_i,'boat_weight: ',boat_weight)
            # print('candidate_i: ',candidate_i,'candidate_weight: ',candidate_weight)
            # print()
            # print('abs(limit-boat_weight):',abs(limit-boat_weight))
            # print('abs(limit-people[next_i])+abs(limit-candidate_weight):',abs(limit-(boat_weight-people[next_i]))+abs(limit-candidate_weight))
            # print()
            # print()
            if abs(limit-boat_weight)<abs(limit-(boat_weight-people[next_i]))+abs(limit-candidate_weight):
                i=next_i+1
                answer+=2
                boat_weight = 0
                people_cnt = 0
            else: # 부족한 것
                if candidate_weight==limit:
                    i=candidate_i+1
                    answer+=2
                else: # 비효율 두번 반복
                    i=next_i
    # print('answer:',answer)
    # print('people_cnt:',people_cnt)
    if boat_weight>0:
        answer+=people_cnt
    # print('i:',i,', p:',people[i],', weight:',boat_weight, 'answer:',answer)
    return answer
            

print(solution([70, 50, 80, 50],100)) # 3
print(solution([70, 80, 50],100)) # 3
print(solution([70, 80, 50, 50, 100, 90, 20, 20, 20, 30],100)) # 6