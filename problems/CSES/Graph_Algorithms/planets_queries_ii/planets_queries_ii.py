import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    t = list(map(int, input().split()))
    t = [x - 1 for x in t]

    LOG = n.bit_length()

    up = [[0] * n for _ in range(LOG)]

    for v in range(n):
        up[0][v] = t[v]

    for j in range(1, LOG):
        for v in range(n):
            up[j][v] = up[j - 1][up[j - 1][v]]

    def jump(v, k):
        j = 0

        while k:
            if k & 1:
                v = up[j][v]

            k >>= 1
            j += 1

        return v

    reverse_graph = [[] for _ in range(n)]
    indegree = [0] * n

    for v in range(n):
        u = t[v]

        reverse_graph[u].append(v)
        indegree[u] += 1

    queue = deque()

    for v in range(n):
        if indegree[v] == 0:
            queue.append(v)

    while queue:
        v = queue.popleft()

        u = t[v]

        indegree[u] -= 1

        if indegree[u] == 0:
            queue.append(u)

    cycle_id = [-1] * n
    cycle_pos = [-1] * n

    cycle_len = []

    visited = [False] * n

    cid = 0

    for start in range(n):
        if indegree[start] == 0 or visited[start]:
            continue

        curr = start
        pos = 0

        while not visited[curr]:
            visited[curr] = True

            cycle_id[curr] = cid
            cycle_pos[curr] = pos

            pos += 1
            curr = t[curr]

        cycle_len.append(pos)
        cid += 1

    depth = [-1] * n
    entry = [-1] * n

    queue = deque()

    for v in range(n):
        if indegree[v] > 0:
            depth[v] = 0
            entry[v] = v
            queue.append(v)

    while queue:
        u = queue.popleft()

        for v in reverse_graph[u]:
            if depth[v] != -1:
                continue

            depth[v] = depth[u] + 1
            entry[v] = entry[u]
            cycle_id[v] = cycle_id[u]

            queue.append(v)

    for _ in range(q):
        a, b = map(int, input().split())

        a -= 1
        b -= 1

        if cycle_id[a] != cycle_id[b]:
            print(-1)
            continue

        if depth[b] > 0:
            if depth[a] < depth[b]:
                print(-1)
                continue

            dist = depth[a] - depth[b]

            if jump(a, dist) == b:
                print(dist)
            else:
                print(-1)

        else:
            start_cycle = entry[a]

            cid = cycle_id[a]
            length = cycle_len[cid]

            cycle_dist = (cycle_pos[b] - cycle_pos[start_cycle] + length) % length

            res = depth[a] + cycle_dist

            print(res)

main()
