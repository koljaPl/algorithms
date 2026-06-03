import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    for k in range(1, n + 1):
        total_squares = (k**2 * (k**2 - 1)) // 2
        attacking_squares = 4 * (k - 1) * (k - 2)

        print(total_squares - attacking_squares)

main()