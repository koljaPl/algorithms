import sys
from collections import defaultdict
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian:
"""
Этот код полностью логически правильный, но изза особености Python (в особенности его скорости)
это решение не пройдет, и как мне кажеться, найти решение на Python которое пройдет тесты будет
весьма проблематично.
"""

# English:
"""
This code is entirely logically correct, but due to a peculiarity of Python (particularly its speed),
this solution will not pass the tests, and I think it will be quite difficult to find a Python solution 
that will pass the tests.
"""

def main():
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))

    count = defaultdict(int)
    count[0] = 1

    prefix = 0
    res = 0

    for x in arr:
        prefix += x

        res += count[prefix - target]

        count[prefix] += 1

    print(res)

main()
