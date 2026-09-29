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
    arr = [0] + list(map(int, input().split()))

    left = [0] * (n + 1)
    right = [0] * (n + 1)
    priority = [0] * (n + 1)

    MASK = (1 << 64) - 1
    seed = 0x123456789ABCDEF

    for i in range(1, n + 1):
        seed ^= (seed << 13) & MASK
        seed ^= seed >> 7
        seed ^= (seed << 17) & MASK
        seed &= MASK

        priority[i] = seed

    def split(root, key):
        if root == 0:
            return 0, 0

        if root < key:
            x, y = split(right[root], key)
            right[root] = x
            return root, y

        x, y = split(left[root], key)
        left[root] = y
        return x, root

    def merge(a_root, b_root):
        if a_root == 0:
            return b_root

        if b_root == 0:
            return a_root

        if priority[a_root] > priority[b_root]:
            right[a_root] = merge(right[a_root], b_root)
            return a_root

        left[b_root] = merge(a_root, left[b_root])
        return b_root

    def insert(root, node):
        if root == 0:
            return node

        if priority[node] > priority[root]:
            l, r = split(root, node)

            left[node] = l
            right[node] = r

            return node

        if node < root:
            left[root] = insert(left[root], node)
        else:
            right[root] = insert(right[root], node)

        return root

    def erase(root, key):
        if root == 0:
            return 0

        if root == key:
            return merge(left[root], right[root])

        if key < root:
            left[root] = erase(left[root], key)
        else:
            right[root] = erase(right[root], key)

        return root

    def predecessor(root, key):
        res = 0

        while root:
            if root < key:
                res = root
                root = right[root]
            else:
                root = left[root]

        return res

    def successor(root, key):
        res = 0

        while root:
            if root > key:
                res = root
                root = left[root]
            else:
                root = right[root]

        return res

    roots = {}
    prev = [0] * (n + 1)
    for i in range(1, n + 1):
        value = arr[i]
        root = roots.get(value, 0)
        prev[i] = predecessor(root, i)
        roots[value] = insert(root, i)

    seg = IterativeSegmentTree(prev[1:], max,0)
    for _ in range(q):
        type_, x, y = map(int, input().split())

        if type_ == 2:
            l = x
            r = y

            mx = seg.query(l - 1, r - 1)

            if mx < l:
                print("YES")
            else:
                print("NO")
        else:
            k = x
            new_value = y

            old_value = arr[k]

            if old_value == new_value:
                continue

            root = roots[old_value]

            old_prev = predecessor(root, k)
            old_next = successor(root, k)

            roots[old_value] = erase(root, k)

            if old_next:
                prev[old_next] = old_prev
                seg.set(old_next - 1, old_prev)

            left[k] = 0
            right[k] = 0

            root = roots.get(new_value, 0)

            new_prev = predecessor(root, k)
            new_next = successor(root, k)

            roots[new_value] = insert(root, k)

            prev[k] = new_prev
            seg.set(k - 1, new_prev)

            if new_next:
                prev[new_next] = k
                seg.set(new_next - 1, k)

            arr[k] = new_value

main()
