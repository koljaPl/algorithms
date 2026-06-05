import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    res = 0
    for i in range(1, n):
        if arr[i] < arr[i - 1]:
            diff = arr[i - 1] - arr[i]

            res += diff
            arr[i] += diff

    print(res)

main()