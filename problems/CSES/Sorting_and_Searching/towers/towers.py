import sys
from bisect import bisect_right
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    cubes = list(map(int, input().split()))

    tops = []
    for cube in cubes:
        pos = bisect_right(tops, cube)

        if pos == len(tops):
            tops.append(cube)
        else:
            tops[pos] = cube

    print(len(tops))

main()
