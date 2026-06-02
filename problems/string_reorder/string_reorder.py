import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    s = input().strip()
    n = len(s)

    cnt = [0] * 26
    for ch in s:
        cnt[ord(ch) - ord('A')] += 1

    if max(cnt) > (n + 1) // 2:
        print(-1)
        return

    res = []
    prev = -1

    for pos in range(n):
        for c in range(26):
            if c == prev or cnt[c] == 0:
                continue

            cnt[c] -= 1

            remaining = n - pos - 1
            mx = max(cnt)

            if mx <= (remaining + 1) // 2:
                res.append(chr(c + ord('A')))
                prev = c
                break

            cnt[c] += 1

    print("".join(res))

main()
