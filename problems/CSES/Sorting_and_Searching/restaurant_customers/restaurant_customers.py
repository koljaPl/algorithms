import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    customers = [list(map(int, input().split())) for _ in range(n)]

    starts = sorted([i[0] for i in customers])
    ends = sorted([i[1] for i in customers])

    res, count = 0, 0
    left, right = 0, 0

    while left < len(customers):
        if starts[left] < ends[right]:
            count += 1
            left += 1
        else:
            count -= 1
            right += 1

        res = max(res, count)

    print(res)

main()
