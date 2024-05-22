def maxHeapify(bag, i, heap_size):
    l=2*i+1
    r=2*i+2
    largest=i
    if l<heap_size and bag[l]>bag[largest]:
        largest=l
    if r<heap_size and bag[r]>bag[largest]:
        largest=r
    if largest!=i:
        bag[i], bag[largest]=bag[largest], bag[i]
        maxHeapify(bag, largest, heap_size)

def build_MAX_Heap(bag):
    heap_size=len(bag)
    for i in range(heap_size//2-1, -1, -1):
        maxHeapify(bag, i, heap_size)

def heapsort(bag):
    build_MAX_Heap(bag)
    heap_size=len(bag)
    for i in range(len(bag)-1, 0, -1):
        bag[0], bag[i]=bag[i], bag[0]
        heap_size-=1
        maxHeapify(bag, 0, heap_size)
    return bag

# 예시 데이터
data=[4, 10, 3, 5, 1]
sorted_data=heapsort(data)
print("Sorted data:", sorted_data)