import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_x = list(map(int, input().split()))

    pos = [0] * (n + 1)
    for index, val in enumerate(list_x):
        pos[val] = index

    res = 1
    for i in range(2, n + 1):
        if pos[i] < pos[i - 1]:
            res += 1

    print(res)

main()
