import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    INF = 10 ** 9

    n, m = map(int, input().split())
    grid = [list(input().strip()) for _ in range(n)]

    monster_dist = [[INF] * m for _ in range(n)]
    player_dist = [[-1] * m for _ in range(n)]

    parent = [[None] * m for _ in range(n)]

    q = deque()

    start = None

    for r in range(n):
        for c in range(m):
            if grid[r][c] == 'M':
                monster_dist[r][c] = 0
                q.append((r, c))
            elif grid[r][c] == 'A':
                start = (r, c)

    directions = [
        (1, 0, 'D'),
        (-1, 0, 'U'),
        (0, 1, 'R'),
        (0, -1, 'L')
    ]

    while q:
        r, c = q.popleft()

        for dr, dc, _ in directions:
            nr = r + dr
            nc = c + dc

            if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != '#' and monster_dist[nr][nc] == INF:
                monster_dist[nr][nc] = monster_dist[r][c] + 1
                q.append((nr, nc))

    sr, sc = start

    if sr == 0 or sr == n - 1 or sc == 0 or sc == m - 1:
        print("YES")
        print(0)
        print()
        sys.exit()

    q = deque([(sr, sc)])
    player_dist[sr][sc] = 0

    end = None

    while q:
        r, c = q.popleft()

        for dr, dc, move in directions:
            nr = r + dr
            nc = c + dc

            if not (0 <= nr < n and 0 <= nc < m):
                continue

            if grid[nr][nc] == '#':
                continue

            if player_dist[nr][nc] != -1:
                continue

            new_dist = player_dist[r][c] + 1

            if new_dist >= monster_dist[nr][nc]:
                continue

            player_dist[nr][nc] = new_dist

            parent[nr][nc] = (r, c, move)

            if nr == 0 or nr == n - 1 or nc == 0 or nc == m - 1:
                end = (nr, nc)
                break

            q.append((nr, nc))

        if end is not None:
            break

    if end is None:
        print("NO")
    else:
        path = []

        r, c = end

        while (r, c) != (sr, sc):
            pr, pc, move = parent[r][c]
            path.append(move)
            r, c = pr, pc

        path.reverse()
        path = ''.join(path)

        print("YES")
        print(len(path))
        print(path)

main()
