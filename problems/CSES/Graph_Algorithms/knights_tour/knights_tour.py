import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOVES = [
    (2, 1), (2, -1),
    (-2, 1), (-2, -1),
    (1, 2), (1, -2),
    (-1, 2), (-1, -2)
]

def main():
    x, y = map(int, input().split())

    x -= 1
    y -= 1

    board = [[0] * 8 for _ in range(8)]

    def degree(r, c):
        count = 0

        for dr, dc in MOVES:
            nr = r + dr
            nc = c + dc

            if 0 <= nr < 8 and 0 <= nc < 8 and board[nr][nc] == 0:
                count += 1

        return count

    def dfs(r, c, step):
        board[r][c] = step

        if step == 64:
            return True

        next_moves = []

        for dr, dc in MOVES:
            nr = r + dr
            nc = c + dc

            if 0 <= nr < 8 and 0 <= nc < 8 and board[nr][nc] == 0:
                next_moves.append((degree(nr, nc), nr, nc))

        # Warnsdorff's rule:
        # first visit cells with fewer available moves
        next_moves.sort()

        for _, nr, nc in next_moves:
            if dfs(nr, nc, step + 1):
                return True

        board[r][c] = 0
        return False

    dfs(y, x, 1)

    for row in board:
        print(*row)

main()
