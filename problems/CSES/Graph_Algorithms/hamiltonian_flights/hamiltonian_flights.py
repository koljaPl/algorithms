import sys
from array import array
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

MOD = 10**9 + 7

def main():
    n, m = map(int, input().split())

    cnt = [[0] * n for _ in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())

        cnt[a - 1][b - 1] += 1

    if n == 2:
        print(cnt[0][1] % MOD)
        return

    k = n - 2

    size = 1 << k

    incoming = [0] * k

    for j in range(k):
        city_j = j + 1

        for u in range(k):
            city_u = u + 1

            if cnt[city_u][city_j]:
                incoming[j] |= 1 << u

    dp = array('I', [0]) * (size * k)

    for j in range(k):
        dp[(1 << j) * k + j] = cnt[0][j + 1] % MOD

    for mask in range(1, size):
        bits = mask

        while bits:
            bit = bits & -bits
            j = bit.bit_length() - 1

            prev_mask = mask ^ bit

            if prev_mask != 0:
                total = 0

                prev_bits = prev_mask & incoming[j]

                while prev_bits:
                    prev_bit = prev_bits & -prev_bits
                    u = prev_bit.bit_length() - 1

                    total += dp[prev_mask * k + u] * cnt[u + 1][j + 1]

                    prev_bits -= prev_bit

                dp[mask * k + j] = total % MOD

            bits -= bit

    full_mask = size - 1

    res = 0

    for j in range(k):
        res += dp[full_mask * k + j] * cnt[j + 1][n - 1]

    print(res % MOD)

main()
