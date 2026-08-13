import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    def can_devide(limit):
        parts = 1
        curr_sum = 0

        for x in arr:
            if curr_sum + x <= limit:
                curr_sum += x
            else:
                parts += 1
                curr_sum = x

                if parts > k:
                    return False

        return True

    left, right = max(arr), sum(arr)

    while left < right:
        mid = left + (right - left) // 2

        if can_devide(mid):
            right = mid
        else:
            left = mid + 1

    print(left)

main()
