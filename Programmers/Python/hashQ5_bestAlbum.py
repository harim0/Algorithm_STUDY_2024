from collections import defaultdict

def solution(genres, plays):
    answer = []
    album_list = defaultdict(int)
    
    for genre, play in zip(genres,plays):
        album_list[genre]+=play
    album_list = sorted(album_list.items(), key=lambda items: items[1], reverse=True)
    
    for genre,_  in album_list:
        tmp_album = [(play, i) for i, (g, play) in enumerate(zip(genres, plays)) if g==genre]
        tmp_album.sort(key=lambda x: (x[0],-x[1]), reverse=True)
        answer.extend(idx for _, idx in tmp_album[:2])
    
    return answer

print(solution(["classic", "pop", "classic", "classic", "pop"],[500, 600, 150, 800, 2500]))