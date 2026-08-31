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

    edges = []

    for _ in range(m):
        a, b, c = map(int, input().split())
        edges.append((c, a - 1, b - 1))

    edges.sort()

    dsu = DSU(n)

    answer = 0
    used_edges = 0

    for cost, a, b in edges:
        if dsu.union(a, b):
            answer += cost
            used_edges += 1

            if used_edges == n - 1:
                break

    if used_edges != n - 1:
        print("IMPOSSIBLE")
    else:
        print(answer)

main()
