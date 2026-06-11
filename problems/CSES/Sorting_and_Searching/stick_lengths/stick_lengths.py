import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_p = sorted(list(map(int, input().split())))

    res = 0
    needed = list_p[n // 2]
    for i in range(n):
        res += abs(list_p[i] - needed)

    print(res)

main()
