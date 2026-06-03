import sys
input = sys.stdin.readline

def main():
    n = int(input())

    if n == 1:
        print(1)
    elif n < 4:
        print("NO SOLUTION")
    else:
        res = []

        for i in range(2, n + 1, 2):
            res.append(i)

        for i in range(1, n + 1, 2):
            res.append(i)

        print(*res)

main()