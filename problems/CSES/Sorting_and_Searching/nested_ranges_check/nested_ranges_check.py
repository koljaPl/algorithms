import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    ranges = []
    for i in range(n):
        x, y = map(int, input().split())
        ranges.append((x, y, i))

    ranges.sort(key=lambda x: (x[0], -x[1]))

    contains = [0] * n
    contained_by = [0] * n

    min_y = float('inf')
    for i in range(n - 1, -1, -1):
        x, y, original_index = ranges[i]
        if y >= min_y:
            contains[original_index] = 1
        else:
            min_y = y

    max_y = 0
    for i in range(n):
        x, y, original_index = ranges[i]
        if y <= max_y:
            contained_by[original_index] = 1
        else:
            max_y = y

    print(*contains)
    print(*contained_by)

main()
