import sys
input = sys.stdin.readline

def main():
    n = int(input())
    list_p = list(map(int, input().split()))

    total = sum(list_p)
    res = float('inf')

    def dfs(i, current_sum):
        nonlocal res

        if i == n:
            res = min(res, abs(total - 2 * current_sum))
            return

        dfs(i + 1, current_sum + list_p[i])

        dfs(i + 1, current_sum)

    dfs(0, 0)

    print(res)

main()
