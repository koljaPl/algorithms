import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n, x = map(int, input().split())

    arr = []

    for i, value in enumerate(map(int, input().split()), start=1):
        arr.append((value, i))

    arr.sort()

    for i in range(n):
        l = i + 1
        r = n - 1

        while l < r:
            s = arr[i][0] + arr[l][0] + arr[r][0]

            if s == x:
                print(arr[i][1], arr[l][1], arr[r][1])
                return

            if s < x:
                l += 1
            else:
                r -= 1

    print("IMPOSSIBLE")

main()
