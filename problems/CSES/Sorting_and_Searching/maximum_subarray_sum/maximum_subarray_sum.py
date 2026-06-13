import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_a = list(map(int, input().split()))

    curr, res = list_a[0], list_a[0]

    for i in range(1, n):
        curr = max(list_a[i], curr + list_a[i])
        res = max(res, curr)

    print(res)

main()