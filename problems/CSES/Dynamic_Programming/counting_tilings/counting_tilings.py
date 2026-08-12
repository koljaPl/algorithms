import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOD = 10**9 + 7

def main():
    n, m = map(int, input().split())

    mask_count = 1 << n
    transitions = [[] for _ in range(mask_count)]

    def generate(row, mask, next_mask):
        if row == n:
            transitions[mask].append(next_mask)
            return

        if mask & (1 << row):
            generate(row + 1, mask, next_mask)
            return

        generate(
            row + 1,
            mask,
            next_mask | (1 << row)
        )

        if row + 1 < n and not (mask & (1 << (row + 1))):
            generate(row + 2, mask, next_mask)

    for mask in range(mask_count):
        generate(0, mask, 0)

    dp = [0] * mask_count
    dp[0] = 1

    for _ in range(m):
        next_dp = [0] * mask_count

        for mask in range(mask_count):
            ways = dp[mask]

            if ways == 0:
                continue

            for next_mask in transitions[mask]:
                next_dp[next_mask] = (next_dp[next_mask] + ways) % MOD

        dp = next_dp

    print(dp[0])

main()
