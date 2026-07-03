import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    arr = map(int, input().split())

    cnt = [0] * n
    cnt[0] = 1

    pref = 0
    res = 0

    for x in arr:
        pref = (pref + x) % n

        res += cnt[pref]
        cnt[pref] += 1

    print(res)

main()
