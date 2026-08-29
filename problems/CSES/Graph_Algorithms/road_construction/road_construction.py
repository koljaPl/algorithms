import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.parents  = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x]) # Path Compression

        return self.parents[x]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        if self.size[u] < self.size[v]:
            u, v = v, u

        self.parents[v] = u
        self.size[u] += self.size[v]

        return True

    def connected(self, a, b):
        return self.find(a) == self.find(b)


def main():
    n, m = map(int, input().split())

    dsu = DSU(n)

    components = n
    largest = 1

    for _ in range(m):
        a, b = map(int, input().split())

        a -= 1
        b -= 1

        if dsu.union(a, b):
            components -= 1

            root = dsu.find(a)
            largest = max(largest, dsu.size[root])

        print(components, largest)

main()
