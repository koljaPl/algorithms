import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    coins = list(map(int, input().split()))

    graph = [[] for _ in range(n)]
    reverse_graph = [[] for _ in range(n)]

    edges = []

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1

        graph[a].append(b)
        reverse_graph[b].append(a)

        edges.append((a, b))

    visited = [False] * n
    order = []

    for start in range(n):
        if visited[start]:
            continue

        stack = [(start, 0)]
        visited[start] = True

        while stack:
            node, index = stack[-1]

            if index < len(graph[node]):
                neighbor = graph[node][index]
                stack[-1] = (node, index + 1)

                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append((neighbor, 0))
            else:
                order.append(node)
                stack.pop()

    component = [-1] * n
    component_count = 0

    for start in reversed(order):
        if component[start] != -1:
            continue

        stack = [start]
        component[start] = component_count

        while stack:
            node = stack.pop()

            for neighbor in reverse_graph[node]:
                if component[neighbor] == -1:
                    component[neighbor] = component_count
                    stack.append(neighbor)

        component_count += 1

    component_coins = [0] * component_count

    for node in range(n):
        component_coins[component[node]] += coins[node]

    dag = [[] for _ in range(component_count)]
    indegree = [0] * component_count

    for a, b in edges:
        ca = component[a]
        cb = component[b]

        if ca != cb:
            dag[ca].append(cb)

    for node in range(component_count):
        if dag[node]:
            dag[node] = list(set(dag[node]))

            for neighbor in dag[node]:
                indegree[neighbor] += 1

    queue = []

    for node in range(component_count):
        if indegree[node] == 0:
            queue.append(node)

    dp = component_coins.copy()

    index = 0

    while index < len(queue):
        node = queue[index]
        index += 1

        for neighbor in dag[node]:
            dp[neighbor] = max(dp[neighbor], dp[node] + component_coins[neighbor])

            indegree[neighbor] -= 1

            if indegree[neighbor] == 0:
                queue.append(neighbor)

    print(max(dp))

main()
