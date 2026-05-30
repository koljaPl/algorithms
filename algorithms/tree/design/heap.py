# Heap - Min Heap and Max Heap

# Min Heap AND Max Heap:
# Height:        O(log n)
#
# Insert:        O(log n)
# Pop:           O(log n)
# Top:           O(1)
# Search:        O(n)
#
# Heapify list:  O(n)

def get_parent(i):
    return (i - 1) // 2

def get_left(i):
    return 2 * i + 1

def get_right(i):
    return 2 * i + 2

class MinHeap:
    def __init__(self):
        self.heap = []

    def swap(self, i, j):
        self.heap[i], self.heap[j] = (
            self.heap[j],
            self.heap[i]
        )

    def sift_up(self, i):
        while i > 0:
            parent = get_parent(i)

            if self.heap[parent] <= self.heap[i]:
                break

            self.swap(parent, i)
            i = parent

    def sift_down(self, i):
        n = len(self.heap)

        while True:
            left = get_left(i)
            right = get_right(i)

            smallest = i

            if left < n and self.heap[left] < self.heap[smallest]:
                smallest = left

            if right < n and self.heap[right] < self.heap[smallest]:
                smallest = right

            if smallest == i:
                break

            self.swap(i, smallest)
            i = smallest

    def push(self, value):
        self.heap.append(value)
        self.sift_up(len(self.heap) - 1)

    def pop(self):
        if not self.heap:
            raise IndexError("Heap is empty")

        minimum = self.heap[0]

        last = self.heap.pop()

        if self.heap:
            self.heap[0] = last
            self.sift_down(0)

        return minimum

    def heapify(self, arr):
        self.heap = arr[:]

        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self.sift_down(i)

    def top(self):
        if not self.heap:
            raise IndexError("Heap is empty")

        return self.heap[0]

    def __len__(self):
        return len(self.heap)

    def __repr__(self):
        return str(self.heap)


class MaxHeap:
    def __init__(self):
        self.heap = []

    def swap(self, i, j):
        self.heap[i], self.heap[j] = (
            self.heap[j],
            self.heap[i]
        )

    def sift_up(self, i):
        while i > 0:
            parent = get_parent(i)

            if self.heap[parent] >= self.heap[i]:
                break

            self.swap(parent, i)
            i = parent

    def sift_down(self, i):
        n = len(self.heap)

        while True:
            left = get_left(i)
            right = get_right(i)

            largest = i

            if left < n and self.heap[left] > self.heap[largest]:
                largest = left

            if right < n and self.heap[right] > self.heap[largest]:
                largest = right

            if largest == i:
                break

            self.swap(i, largest)
            i = largest

    def push(self, value):
        self.heap.append(value)
        self.sift_up(len(self.heap) - 1)

    def pop(self):
        if not self.heap:
            raise IndexError("Heap is empty")

        maximum = self.heap[0]

        last = self.heap.pop()

        if self.heap:
            self.heap[0] = last
            self.sift_down(0)

        return maximum

    def heapify(self, arr):
        self.heap = arr[:]

        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self.sift_down(i)

    def top(self):
        if not self.heap:
            raise IndexError("Heap is empty")

        return self.heap[0]

    def __len__(self):
        return len(self.heap)

    def __repr__(self):
        return str(self.heap)

# Intuition / Idea:
# "Сделать так, чтобы самый важный элемент ( обычно самый дешевый/дорогой ) всегда находился сверху"
#
# Основная идея:
# Heap хранит элементы так, чтобы выполнялось правило:
#
# Для каждого узла:
#
# родитель <= дети
# ( для Min Heap )
#
# Например:
#
#         1
#       /   \
#      2     3
#     / \   / \
#    7  5 10  8
#
# Тут:
#
# 1 <= 2, 3
# 2 <= 7, 5
# 3 <= 10, 8
#
# Поэтому минимум всегда находится в корне.

# Tss, there is something cool about max heap, there is how we do this in Python:

# import heapq # Just a cool pythonic library with heap implementation

# heap = []

# heapq.heappush(heap, -10)
# heapq.heappush(heap, -5)
# heapq.heappush(heap, -20)

# print(-heapq.heappop(heap))

# See? It's just numbers with - and we print it also like - so we get anti-min-heap what is max heap.

# ---------------------------------------------------------------------------------------------------

# Where can we use it (Problems like Codeforces and AtCoder)?

# 1. Find minimum/maximum (specially many times or dynamically)
# 2. Top K (k largest or k smallest)
# 3. "Elements are always coming"
# 4. Priority Matters
# 5. Shortest Something (like path, in that thing we can add his Majesty the Dijkstra algorithm,
#                        the rising star A*, and, for example, best-first search)
# 6. Closest Something (like k the closest points)
# 7. Data Stream (stream, online, real-time)

# But the best way to use heap is dynamic minimum/maximum