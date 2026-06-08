import sys
from collections import deque

input = sys.stdin.readline

def main():
    moves = [
        (-2, -1), (-2, 1),
        (-1, -2), (-1, 2),
        (1, -2), (1, 2),
        (2, -1), (2, 1)
    ]
    n = int(input())

    dist = [[-1] * n for _ in range(n)]

    q = deque([(0, 0)])
    dist[0][0] = 0

    while q:
        x, y = q.popleft()

        for dx, dy in moves:
            nx, ny = x + dx, y + dy

            if 0 <= nx < n and 0 <= ny < n and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))

    for row in dist:
        print(*row)

main()
