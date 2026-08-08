import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))

    sum, res = 0, 0

    left = 0

    for right in range(len(arr)):
        sum += arr[right]

        while sum > target:
            sum -= arr[left]
            left += 1

        if sum == target:
            res += 1

    print(res)

main()
