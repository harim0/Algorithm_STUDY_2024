def solution1(phone_book):
    phone_book.sort()
    for i in range(len(phone_book)-1):
        if phone_book[i]==phone_book[i+1][:len(phone_book[i])]:
            return False
    return True

def solution(phone_book):
    hash_map={}
    for number in phone_book:
        hash_map[number]=1
    for phone_num in phone_book:
        tmp = ''
        for number in phone_num:
            tmp+=number
            if tmp in hash_map and tmp!=phone_num:
                return False
    return True

print(solution(["119", "97674223", "1195524421"]))
print(solution(["123","456","789"]))
print(solution(["12","123","1235","567","88"]))