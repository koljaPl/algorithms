import sys
input = sys.stdin.readline

def main():
    n = int(input())

    moves = []

    def hanoi(count, start, end, aux):
        if count == 1:
            moves.append((start, end))
            return

        hanoi(count - 1, start, aux, end)

        moves.append((start, end))

        hanoi(count - 1, aux, end, start)

    hanoi(n, 1, 3, 2)

    print(len(moves))

    for a, b in moves:
        print(a, b)

main()
