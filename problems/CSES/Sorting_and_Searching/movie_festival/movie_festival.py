import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    movies = [list(map(int, input().split())) for _ in range(n)]

    movies.sort(key=lambda x: x[1])

    res = 0
    last_end = 0

    for start, end in movies:
        if start >= last_end:
            res += 1
            last_end = end

    print(res)

main()