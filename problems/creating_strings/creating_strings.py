import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    s = list(input().strip())
    n = len(s)

    used = [False] * n
    res = set()

    def backtracking(curr_s, length):
        if length == n:
            res.add(curr_s)
            return

        for i in range(n):
            if not used[i]:
                used[i] = True
                backtracking(curr_s + s[i], length + 1)
                used[i] = False

        return

    backtracking("", 0)

    res = sorted(list(res))

    print(len(res))

    for string in res:
        print(string)

main()