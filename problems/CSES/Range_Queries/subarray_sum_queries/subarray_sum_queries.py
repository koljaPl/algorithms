import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian
'''
Решение для этой задачи логически правильное, но изза того что Python не очень быстрый,
легче написать решение для этоц задачи на C++.
'''

# English
'''
The solution to this problem is logically correct, but since Python isn't very fast,
it's easier to write a solution to this problem in C++.
'''

def make_node(x):
    v = max(0, x)
    return (x, v, v, v)

def merge(a, b):
    sum_a, pref_a, suff_a, best_a = a
    sum_b, pref_b, suff_b, best_b = b

    total = sum_a + sum_b

    pref = max(pref_a, sum_a + pref_b)
    suff = max(suff_b, sum_b + suff_a)
    best = max(best_a, best_b, suff_a + pref_b)

    return (total, pref, suff, best)

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

    def max_subarray(self):
        return self.tree[1][3]

def main():
    n, m = map(int, input().split())
    arr = [make_node(int(x)) for x in input().split()]
    st = IterativeSegmentTree(arr, merge, (0, 0, 0, 0))

    for _ in range(m):
        k, x = map(int, input().split())
        st.set(k - 1, make_node(x))

        print(st.max_subarray())

main()
