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
    n = int(input())
    heights = list(map(int, input().split()))

    left = [-1] * n
    right = [n] * n

    stack = []

    for i in range(n):
        while stack and heights[stack[-1]] < heights[i]:
            stack.pop()

        if stack:
            left[i] = stack[-1]

        stack.append(i)

    stack.clear()

    for i in range(n - 1, -1, -1):
        while stack and heights[stack[-1]] < heights[i]:
            stack.pop()

        if stack:
            right[i] = stack[-1]

        stack.append(i)

    order = sorted(range(n), key=heights.__getitem__)

    st = IterativeSegmentTree(
        [0] * n,
        max,
        0
    )

    dp = [1] * n

    res = 1
    group_start = 0

    while group_start < n:
        group_end = group_start
        curr_height = heights[order[group_start]]

        while (
                group_end < n
                and heights[order[group_end]] == curr_height
        ):
            group_end += 1

        for k in range(group_start, group_end):
            index = order[k]

            best_next = st.query(
                left[index] + 1,
                right[index] - 1
            )

            dp[index] = best_next + 1
            res = max(res, dp[index])

        for k in range(group_start, group_end):
            index = order[k]
            st.set(index, dp[index])

        group_start = group_end

    print(res)

main()
