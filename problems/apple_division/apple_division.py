import sys
input = sys.stdin.readline

def main():
    n = int(input())
    list_p = list(map(int, input().split()))

    total = sum(list_p)
    res = float('inf')

    for mask in range(1 << n):
        subset_sum = 0

        for i in range(n):
            if mask & (1 << i):
                subset_sum += list_p[i]

        res = min(res, abs(total - 2 * subset_sum))

    print(res)

main()
