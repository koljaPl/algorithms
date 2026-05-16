# Segment Tree:
#
# Time Complexity:
# Query:    O(log n)
# Update:   O(log n)
# Build:  	O(n)
#
# Space Complexity:
# Memory:   O(4 * n)

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)

        self.arr = arr[:]
        self.tree = [0] * (4 * self.n)

        self.built(1, 0, self.n - 1)

    def built(self, node, left, right):
        if left == right:
            self.tree[node] = self.arr[left]
            return

        mid = left + (right - left) // 2
        self.built(node * 2, left, mid)
        self.built(node * 2 + 1, mid + 1, right)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def query(self, start, end):
        return self.helper_query(1, 0, self.n - 1, start, end)

    def helper_query(self, node, left, right, start, end):
        if end < left or right < start:
            return 0

        if start <= left and right <= end:
            return self.tree[node]

        mid = (left + right) // 2

        s1 = self.helper_query(node * 2, left, mid, start, end)
        s2 = self.helper_query(node * 2 + 1, mid + 1, right, start, end)

        return s1 + s2

    def update(self, index, value):
        self.helper_update(1, 0, self.n - 1, index, value)

    def helper_update(self, node, left, right, index, value):
        if left == right:
            self.tree[node] = value
            return

        mid = (left + right) // 2
        if index <= mid:
            self.helper_update(node * 2, left, mid, index, value)
        else:
            self.helper_update(node * 2 + 1, mid + 1, right, index, value)

        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]


class IterativeSegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.size = 1
        while self.size < self.n:
            self.size *= 2

        self.tree = [0] * (2 * self.size)

        for i in range(self.n):
            self.tree[self.size + i] = arr[i]

        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.tree[i * 2] + self.tree[i * 2 + 1]

    def set(self, idx, value):
        pos = self.size + idx
        self.tree[pos] = value
        pos //= 2

        while pos >= 1:
            self.tree[pos] = self.tree[pos * 2] + self.tree[pos * 2 + 1]
            pos //= 2

    def query(self, left, right):
        left += self.size
        right += self.size
        res = 0

        while left < right:
            if left % 2 == 1:
                res += self.tree[left]
                left += 1
            if right % 2 == 1:
                right -= 1
                res += self.tree[right]
            left //= 2
            right //= 2

        return res

# How to use:

# arr = [5, 2, 7, 3, 6, 1]
# st = SegmentTree(arr)
# st = IterativeSegmentTree(arr)

# print(st.query(1, 3)) # Sum

# When to use:
# Он очень часто встречается в задачах типа:
#
# “поддерживать массив и отвечать на запросы на отрезке”
# “обновить элемент, спросить минимум на диапазоне”
# “найти первый индекс, где сумма префикса достигнет X”
# “поддержка массовых обновлений на отрезке”
#
# На Codeforces / AtCoder / CSES это одна из базовых структур.
#
# Представляй, что Segment Tree — это не “дерево ради дерева”, а таблица ответов по кускам массива.

# листья — отдельные элементы
# родители — ответы на объединенные куски
# корень — ответ на весь массив
#
# И когда приходят запросы, ты не пересчитываешь всё заново, а просто используешь уже готовые куски.