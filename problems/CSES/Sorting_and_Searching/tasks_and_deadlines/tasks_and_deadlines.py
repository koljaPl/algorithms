import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    tasks = [list(map(int, input().split())) for _ in range(n)]

    tasks.sort(key=lambda x: x[0])

    time = 0
    res = 0

    for a, d in tasks:
        time += a
        res += d - time

    print(res)

main()
