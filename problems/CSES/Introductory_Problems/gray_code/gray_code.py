import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Time Complexity:
# O( n * 2**n )
# Space Complexity:
# Memory: O( n * 2**n )
def main():
    n = int(input())

    gray = [""]

    for _ in range(n):
        gray = ["0" + x for x in gray] + \
               ["1" + x for x in reversed(gray)]

    print(*gray, sep="\n")

main()
