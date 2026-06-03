import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main_v1():
    n = int(input())

    res = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            res[i][j] = i ^ j

    for line in res:
        print(*line)

def main_v2():
    n = int(input())

    for i in range(n):
        for j in range(n):
            print(i ^ j, end=" ")
        print()

main_v2()