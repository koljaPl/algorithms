import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, t = map(int, input().split())
    list_k = list(map(int, input().split()))

    left = 0
    right = min(list_k) * t

    while left < right:
        mid = left + (right - left) // 2

        count = 0
        for machine in list_k:
            count += mid // machine

            if count >= t:
                break

        if count >= t:
            right = mid
        else:
            left = mid + 1

    print(left)

main()
