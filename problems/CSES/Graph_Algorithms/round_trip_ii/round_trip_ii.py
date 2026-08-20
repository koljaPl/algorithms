import sys
sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)

    state = [0] * (n + 1)

    parent = [-1] * (n + 1)

    cycle_start = -1
    cycle_end = -1

    def dfs(u):
        nonlocal cycle_start, cycle_end

        state[u] = 1

        for v in graph[u]:
            if state[v] == 0:
                parent[v] = u

                if dfs(v):
                    return True

            elif state[v] == 1:
                cycle_start = v
                cycle_end = u
                return True

        state[u] = 2
        return False

    for i in range(1, n + 1):
        if state[i] == 0:
            if dfs(i):
                break

    if cycle_start == -1:
        print("IMPOSSIBLE")
        return

    cycle = [cycle_start]

    cur = cycle_end

    while cur != cycle_start:
        cycle.append(cur)
        cur = parent[cur]

    cycle.append(cycle_start)

    cycle.reverse()

    print(len(cycle))
    print(*cycle)

main()
