class MaxHeap:
    def __init__(self):
        self.heap = []
    
    def size(self):
        return len(self.heap)

    def push(self, val):
        self.heap.append(val)
        self._sift_up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sift_down(0)
        return root

    def _sift_up(self, i):
        parent = (i - 1) // 2
        if i > 0 and self.heap[i] > self.heap[parent]:
            self.heap[i], self.heap[parent] = self.heap[parent], self.heap[i]
            self._sift_up(parent)

    def _sift_down(self, i):
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < len(self.heap) and self.heap[l] > self.heap[largest]:
            largest = l
        if r < len(self.heap) and self.heap[r] > self.heap[largest]:
            largest = r

        if largest != i:
            self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
            self._sift_down(largest)
        
n, k = map(int, input().split())
jewries = []
bag_limit = []
for i in range(n):
    m,v = map(int, input().split())
    jewries.append((m,v))
for i in range(k):
    limit = int(input())
    bag_limit.append(limit)
jewries.sort(key=lambda jewries: (jewries[0], -jewries[1]))
bag_limit.sort()
heap_size = len(jewries)

answer = 0
my_bag = MaxHeap()
j = 0
for i in range(k):
    max_jewry = 0
    while j<n and jewries[j][0]<=bag_limit[i]:
        my_bag.push(jewries[j][1])
        j+=1
    if my_bag.size()!=0:
        answer+=my_bag.pop()

print(answer)
