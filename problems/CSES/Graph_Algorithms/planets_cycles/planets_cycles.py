import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    to = [x - 1 for x in map(int, input().split())]

    state = [0] * n

    res = [0] * n

    for start in range(n):
        if state[start] != 0:
            continue

        path = []
        v = start

        while state[v] == 0:
            state[v] = 1
            path.append(v)
            v = to[v]

        if state[v] == 1:
            cycle_start = 0

            while path[cycle_start] != v:
                cycle_start += 1

            cycle_length = len(path) - cycle_start

            for i in range(cycle_start, len(path)):
                res[path[i]] = cycle_length

            for i in range(cycle_start - 1, -1, -1):
                node = path[i]
                res[node] = res[to[node]] + 1

        else:
            for i in range(len(path) - 1, -1, -1):
                node = path[i]
                res[node] = res[to[node]] + 1

        for node in path:
            state[node] = 2

    print(*res)

main()
