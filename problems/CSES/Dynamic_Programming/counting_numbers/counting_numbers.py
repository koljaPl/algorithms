import sys
from functools import lru_cache
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def count_valid(x: int) -> int:
    if x < 0:
        return 0

    digits = str(x)
    n = len(digits)

    @lru_cache(maxsize=None)
    def dp(
        pos: int,
        previous: int,
        tight: bool,
        started: bool
    ) -> int:
        if pos == n:
            return 1

        limit = int(digits[pos]) if tight else 9
        res = 0

        for digit in range(limit + 1):
            next_tight = tight and digit == limit

            if not started and digit == 0:
                res += dp(
                    pos + 1,
                    10,
                    next_tight,
                    False
                )
                continue

            if started and digit == previous:
                continue

            res += dp(
                pos + 1,
                digit,
                next_tight,
                True
            )

        return res

    return dp(0, 10, True, False)

def main():
    a, b = map(int, input().split())

    print(count_valid(b) - count_valid(a - 1))

main()
