from collections import defaultdict

def solution(genres, plays):
    answer = []
    album_list = defaultdict(int)
    
    for i in range(len(plays)):
        album_list[genres[i]]+=plays[i]
    album_list = dict(sorted(album_list.items(), key=lambda items: items[1], reverse=True))
    
    for album_type in album_list.keys():
        tmp_album = []
        for i in range(len(genres)):
            if album_type==genres[i]:
                tmp_album.append((plays[i],i))
        tmp_album.sort()
        for i in range(2):
            answer.append(tmp_album.pop()[1])
    
    return answer

print(solution(["classic", "pop", "classic", "classic", "pop"],[500, 600, 150, 800, 2500]))