import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_k = list(map(int, input().split()))

    seen = set()
    left = 0
    res = 0

    for right in range(n):
        while list_k[right] in seen:
            seen.remove(list_k[left])
            left += 1

        seen.add(list_k[right])
        res = max(res, right - left + 1)

    print(res)

main()
