class MaxHeap:
    def __init__(self):
        self.heap = []

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

# 사용 예제
heap = MaxHeap()
data = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

for num in data:
    heap.push(num)

while len(heap.heap) > 0:
    print(heap.pop(), end=' ')  # 최대 힙에서 요소를 하나씩 제거하며 출력
