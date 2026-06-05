import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    s = sorted(list(input().strip()))
    n = len(s)

    used = [False] * n
    res = []

    def backtracking(curr):
        if len(curr) == n:
            res.append("".join(curr))
            return

        for i in range(n):
            if used[i]:
                continue

            if i > 0 and s[i] == s[i - 1] and not used[i - 1]:
                continue

            used[i] = True
            curr.append(s[i])

            backtracking(curr)

            curr.pop()
            used[i] = False

        return

    backtracking([])

    print(len(res))

    for string in res:
        print(string)

main()
