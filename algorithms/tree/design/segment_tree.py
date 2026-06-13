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
    def __init__(self, arr, merge, identity):
        self.n = len(arr)
        self.arr = arr[:]
        self.tree = [identity] * (4 * self.n)

        self.merge = merge
        self.identity = identity

        self.build(1, 0, self.n - 1)

    def build(self, node, left, right):
        if left == right:
            self.tree[node] = self.arr[left]
            return

        mid = left + (right - left) // 2

        self.build(node * 2, left, mid)
        self.build(node * 2 + 1, mid + 1, right)

        self.tree[node] = self.merge(
            self.tree[node * 2],
            self.tree[node * 2 + 1]
        )

    def query(self, start, end):
        return self.helper_query(1, 0, self.n - 1, start, end)

    def helper_query(self, node, left, right, start, end):
        if end < left or right < start:
            return self.identity

        if start <= left and right <= end:
            return self.tree[node]

        mid = left + (right - left) // 2

        left_side = self.helper_query(node * 2, left, mid, start, end)
        right_side = self.helper_query(node * 2 + 1, mid + 1, right, start, end)

        return self.merge(left_side, right_side)

    def update(self, index, value):
        self.helper_update(1, 0, self.n - 1, index, value)

    def helper_update(self, node, left, right, index, value):
        if left == right:
            self.tree[node] = value
            return

        mid = left + (right - left) // 2

        if index <= mid:
            self.helper_update(node * 2, left, mid, index, value)
        else:
            self.helper_update(node * 2 + 1, mid + 1, right, index, value)

        self.tree[node] = self.merge(
            self.tree[node * 2],
            self.tree[node * 2 + 1]
        )


class IterativeSegmentTree:
    def __init__(self, arr, merge, identity):
        self.n = len(arr)
        self.size = 1
        while self.size < self.n:
            self.size *= 2

        self.tree = [identity] * (2 * self.size)

        self.merge = merge
        self.identity = identity

        for i in range(self.n):
            self.tree[self.size + i] = arr[i]

        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.merge(
                self.tree[i * 2],
                self.tree[i * 2 + 1]
            )

    def set(self, idx, value):
        pos = self.size + idx
        self.tree[pos] = value

        pos //= 2
        while pos >= 1:
            self.tree[pos] = self.merge(
                self.tree[2 * pos],
                self.tree[2 * pos + 1]
            )
            pos //= 2

    def query(self, left, right):
        left += self.size
        right += self.size + 1

        res_left = self.identity
        res_right = self.identity

        while left < right:
            if left % 2 == 1:
                res_left = self.merge(res_left, self.tree[left])
                left += 1
            if right % 2 == 1:
                right -= 1
                res_right = self.merge(self.tree[right], res_right)

            left //= 2
            right //= 2

        return self.merge(res_left, res_right)

# Intuition / Idea:
# Представь массив как длинную линию.
# Вместо того чтобы каждый раз пересчитывать что-то на отрезке заново,
# мы заранее разбиваем массив на "кусочки" и храним ответы для них.
#
# Но не просто кусочки, а иерархически:
#
# весь массив — корень дерева
# он делится на 2 половины
# каждая половина снова делится на 2
# и так до отдельных элементов
#
# Получается как "дерево отрезков", где каждый узел хранит информацию о своём диапазоне.
#
# Каждый узел хранит ответ для отрезка [l, r], например:
# сумму
# минимум
# максимум
# gcd
# и т.д.
#
# И если тебе нужен ответ на запрос, например:
# сумма на [L, R] то ты берёшь только те узлы, которые полностью покрывают
# части запроса и не заходишь внутрь уже “готовых” отрезков

# How to use:

# SUM tree:
# st = SegmentTree(
#     arr,
#     merge=lambda a, b: a + b,
#     identity=0
# )

# MIN tree:
# st = SegmentTree(
#     arr,
#     merge=min,
#     identity=10**18
# )

# MAX tree:
# st = SegmentTree(
#     arr,
#     merge=max,
#     identity=-10**18
# )

# XOR tree:
# st = SegmentTree(
#     arr,
#     merge=lambda a, b: a ^ b,
#     identity=0
# )

# GCD tree
# import math
#
# st = SegmentTree(
#     arr,
#     merge=math.gcd,
#     identity=0
# )
#
# and then full code:
#
# n, q = map(int, input().split())
# arr = list(map(int, input().split()))
#
# st = SegmentTree(arr, lambda a, b: a + b, 0)
#
# for _ in range(q):
#     t = input().split()
#
#     if t[0] == "query":
#         l = int(t[1])
#         r = int(t[2])
#
#         print(st.query(l, r))
#
#     else:
#         idx = int(t[1])
#         val = int(t[2])
#
#         st.update(idx, val)

# When to use:
# Он очень часто встречается в задачах типа:
#
# "поддерживать массив и отвечать на запросы на отрезке"
# "обновить элемент, спросить минимум на диапазоне"
# "найти первый индекс, где сумма префикса достигнет X"
# "поддержка массовых обновлений на отрезке"
#
# На Codeforces / AtCoder / CSES это одна из базовых структур.
#
# Представляй, что Segment Tree — это не “дерево ради дерева”, а таблица ответов по кускам массива.

# листья — отдельные элементы
# родители — ответы на объединенные куски
# корень — ответ на весь массив
#
# И когда приходят запросы, ты не пересчитываешь всё заново, а просто используешь уже готовые куски.
