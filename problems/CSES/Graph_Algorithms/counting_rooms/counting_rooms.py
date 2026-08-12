import sys
from collections import deque
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    grid = [list(input().strip()) for _ in range(n)]

    rooms = 0

    directions = [
        (1, 0),
        (-1, 0),
        (0, 1),
        (0, -1)
    ]

    for r in range(n):
        for c in range(m):
            if grid[r][c] != '.':
                continue

            rooms += 1

            q = deque()
            q.append((r, c))
            grid[r][c] = '#'

            while q:
                row, col = q.popleft()

                for dr, dc in directions:
                    nr = row + dr
                    nc = col + dc

                    if (
                            0 <= nr < n
                            and 0 <= nc < m
                            and grid[nr][nc] == '.'
                    ):
                        grid[nr][nc] = '#'
                        q.append((nr, nc))

    print(rooms)

main()
