import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    hotels = list(map(int, input().split()))
    groups = list(map(int, input().split()))

    size = 1
    while size < n:
        size *= 2

    tree = [0] * (2 * size)
    for i in range(n):
        tree[size + i] = hotels[i]

    for i in range(size - 1, 0, -1):
        tree[i] = max(tree[2 * i], tree[2 * i + 1])

    def allocate(x):
        if tree[1] < x:
            return 0

        node = 1

        while node < size:
            if tree[2 * node] >= x:
                node = 2 * node
            else:
                node = 2 * node + 1

        hotel = node - size

        tree[node] -= x

        node //= 2
        while node:
            tree[node] = max(tree[2 * node], tree[2 * node + 1])
            node //= 2

        return hotel + 1

    result = [allocate(x) for x in groups]
    print(*result)

main()
