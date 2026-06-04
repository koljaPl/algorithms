import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, m, k = map(int, input().split())
    list_a = sorted(list(map(int, input().split())))
    list_b = sorted(list(map(int, input().split())))

    res = 0
    i = j = 0
    while i < n and j < m:
        if list_b[j] < list_a[i] - k:
            j += 1
        elif list_b[j] > list_a[i] + k:
            i += 1
        else:
            res += 1
            i += 1
            j += 1

    print(res)

main()
