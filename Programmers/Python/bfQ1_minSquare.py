
def solution(sizes):
    answer = 1000000
    while(True):
        max_zero = (0,0,0)
        max_one = (0,0,0)
        for i in range(len(sizes)):
            if max_zero[0]<sizes[i][0]:
                max_zero = (sizes[i][0],sizes[i][1],i)
            if max_one[1]<sizes[i][1]:
                max_one = (sizes[i][0],sizes[i][1],i)
        card_size = max_zero[0]*max_one[1]
        if answer>card_size:
            answer = card_size
        if max_zero[0]<=max_one[1] and max_zero[1]<max_zero[0]:
            sizes[max_zero[2]][0],sizes[max_zero[2]][1]=sizes[max_zero[2]][1],sizes[max_zero[2]][0]
        elif max_one[1]<max_zero[0] and max_one[0]<max_one[1]:
            sizes[max_one[2]][0],sizes[max_one[2]][1]=sizes[max_one[2]][1],sizes[max_one[2]][0]
        else:
            break
            
    return answer

# def solution_gpt(sizes):
#     max_width = 0
#     max_height = 0
    
#     for width, height in sizes:
#         max_width = max(max_width, width, height)
#         max_height = max(max_height, min(width, height))
        
#     return max_width * max_height

print(solution([[60, 50], [30, 70], [60, 30], [80, 40]]))
print(solution([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]))
print(solution([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]))
