import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(2 * m)]
    reverse_graph = [[] for _ in range(2 * m)]

    def get_node(sign, x):
        x -= 1

        if sign == '+':
            return 2 * x
        else:
            return 2 * x + 1

    def add_edge(u, v):
        graph[u].append(v)
        reverse_graph[v].append(u)

    for _ in range(n):
        s1, x1, s2, x2 = input().split()

        a = get_node(s1, int(x1))
        b = get_node(s2, int(x2))

        add_edge(a ^ 1, b)
        add_edge(b ^ 1, a)

    visited = [False] * (2 * m)
    order = []

    for start in range(2 * m):
        if visited[start]:
            continue

        stack = [(start, 0)]
        visited[start] = True

        while stack:
            v, i = stack[-1]

            if i < len(graph[v]):
                to = graph[v][i]
                stack[-1] = (v, i + 1)

                if not visited[to]:
                    visited[to] = True
                    stack.append((to, 0))
            else:
                order.append(v)
                stack.pop()

    component = [-1] * (2 * m)
    component_id = 0

    for start in reversed(order):
        if component[start] != -1:
            continue

        stack = [start]
        component[start] = component_id

        while stack:
            v = stack.pop()

            for to in reverse_graph[v]:
                if component[to] == -1:
                    component[to] = component_id
                    stack.append(to)

        component_id += 1

    res = []
    for i in range(m):
        positive = 2 * i
        negative = positive + 1

        if component[positive] == component[negative]:
            print("IMPOSSIBLE")
            return

        if component[positive] > component[negative]:
            res.append('+')
        else:
            res.append('-')

    print(*res)

main()