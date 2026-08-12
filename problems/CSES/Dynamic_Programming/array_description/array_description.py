import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    MOD = 10 ** 9 + 7

    n, m = map(int, input().split())
    arr = list(map(int, input().split()))

    prev = [0] * (m + 2)

    if arr[0] == 0:
        for value in range(1, m + 1):
            prev[value] = 1
    else:
        prev[arr[0]] = 1

    for i in range(1, n):
        curr = [0] * (m + 2)

        if arr[i] == 0:
            for value in range(1, m + 1):
                curr[value] = (prev[value - 1] + prev[value] + prev[value + 1]) % MOD
        else:
            value = arr[i]
            curr[value] = (prev[value - 1] + prev[value] + prev[value + 1]) % MOD

        prev = curr

    print(sum(prev) % MOD)

main()
