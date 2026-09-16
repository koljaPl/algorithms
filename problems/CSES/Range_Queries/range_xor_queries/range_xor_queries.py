import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

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

def main():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    st = IterativeSegmentTree(arr, merge=lambda a, b: a ^ b, identity=0)

    for _ in range(q):
        a, b = map(int, input().split())
        print(st.query(a - 1, b - 1))

main()
