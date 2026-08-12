import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    grid = [input().strip() for _ in range(n)]

    start = None
    end = None

    for r in range(n):
        for c in range(m):
            if grid[r][c] == "A":
                start = (r, c)
            elif grid[r][c] == "B":
                end = (r, c)

    directions = [
        (-1, 0, "U"),
        (1, 0, "D"),
        (0, -1, "L"),
        (0, 1, "R"),
    ]

    queue = deque([start])

    visited = [[False] * m for _ in range(n)]
    visited[start[0]][start[1]] = True

    parent = [[""] * m for _ in range(n)]

    while queue:
        r, c = queue.popleft()

        if (r, c) == end:
            break

        for dr, dc, move in directions:
            nr = r + dr
            nc = c + dc

            if (
                    0 <= nr < n
                    and 0 <= nc < m
                    and grid[nr][nc] != "#"
                    and not visited[nr][nc]
            ):
                visited[nr][nc] = True
                parent[nr][nc] = move
                queue.append((nr, nc))

    if not visited[end[0]][end[1]]:
        print("NO")
    else:
        path = []

        r, c = end

        while (r, c) != start:
            move = parent[r][c]
            path.append(move)

            if move == "U":
                r += 1
            elif move == "D":
                r -= 1
            elif move == "L":
                c += 1
            elif move == "R":
                c -= 1

        path.reverse()

        print("YES")
        print(len(path))
        print("".join(path))

main()
