import sys
input = sys.stdin.readline

def main():
    board = [input() for _ in range(8)]

    cols = [False] * 8
    diag1 = [False] * 15
    diag2 = [False] * 15

    res = 0

    def dfs(row):
        nonlocal res

        # Если все 8 ферзей поставлены
        if row == 8:
            res += 1
            return

        # Пробуем поставить ферзя в каждый столбец
        for col in range(8):

            # Если запрещённая клетка
            if board[row][col] == "*":
                continue

            d1 = row - col + 7
            d2 = row + col

            # Если кто-то атакует
            if cols[col] or diag1[d1] or diag2[d2]:
                continue

            # Ставим ферзя
            cols[col] = True
            diag1[d1] = True
            diag2[d2] = True

            dfs(row + 1)

            # Убераем ферзя (backtracking)
            cols[col] = False
            diag1[d1] = False
            diag2[d2] = False

    dfs(0)

    print(res)

main()
