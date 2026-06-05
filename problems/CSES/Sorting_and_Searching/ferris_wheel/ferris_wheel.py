import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# O( n log n )
def main():
    n, x = map(int, input().split())
    list_p = sorted(list(map(int, input().split())))

    i = 0
    j = n - 1
    res = 0

    while i <= j:
        if i == j:
            res += 1
            break

        if list_p[i] + list_p[j] <= x:
            i += 1
            j -= 1
        else:
            j -= 1

        res += 1

    print(res)

main()
