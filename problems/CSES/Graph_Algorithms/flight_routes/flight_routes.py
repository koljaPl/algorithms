import sys
import heapq
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

def main():
    n, m, k = map(int, input().split())

    graph = [[] for _ in range(n)]
    for i in range(m):
        a, b, w = map(int, input().split())
        graph[a - 1].append((b - 1, w))

    count = [0] * n
    priority_queue = [(0, 0)]
    res = []

    while priority_queue and len(res) < k:
        cost, u = heapq.heappop(priority_queue)

        if count[u] >= k:
            continue

        count[u] += 1

        if u == n - 1:
            res.append(cost)

        for v, w in graph[u]:
            if count[v] < k:
                heapq.heappush(priority_queue, (cost + w, v))

    print(*res)

main()
