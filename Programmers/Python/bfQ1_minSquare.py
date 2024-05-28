def choices(sizes, newChoices, idx, i):
    if i>=0:
        newChoices.append((sizes[i][idx], sizes[i][idx^1]))
    if i==len(sizes)-1:
        max_weight = max(item[0] for item in newChoices)
        max_height = max(item[1] for item in newChoices)
        # print('newChoices: ',newChoices)
        # print('max_weight: ',max_weight,', max_height: ',max_height)
        # print()
        return max_weight*max_height
    else:
        return min(choices(sizes, newChoices[:], 0, i+1), choices(sizes, newChoices[:], 1, i+1))

def solution(sizes):
    return choices(sizes, [], 0, -1)

print(solution([[60, 50], [30, 70], [60, 30], [80, 40]]))
print(solution([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]))
print(solution([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]))
