import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    grid = [input().strip() for _ in range(n)]

    frontier = [0]
    res = [grid[0][0]]

    seen = [0] * n
    stamp = 0

    for diagonal in range(1, 2 * n - 1):
        stamp += 1
        candidates = []
        best_char = "["

        for row in frontier:
            previous_col = diagonal - 1 - row

            if previous_col + 1 < n and seen[row] != stamp:
                seen[row] = stamp
                candidates.append(row)

                col = diagonal - row
                best_char = min(best_char, grid[row][col])

            next_row = row + 1

            if next_row < n and seen[next_row] != stamp:
                seen[next_row] = stamp
                candidates.append(next_row)

                col = diagonal - next_row
                best_char = min(best_char, grid[next_row][col])

        frontier = [
            row
            for row in candidates
            if grid[row][diagonal - row] == best_char
        ]

        res.append(best_char)

    print("".join(res))

main()
