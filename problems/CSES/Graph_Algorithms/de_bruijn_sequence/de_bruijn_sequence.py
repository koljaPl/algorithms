import sys
sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())

    if n == 1:
        print("01")
        return

    size = 1 << (n - 1)
    mask = size - 1

    used = [0] * size
    res = []

    def dfs(v):
        while used[v] < 2:
            bit = used[v]
            used[v] += 1

            u = ((v << 1) | bit) & mask

            dfs(u)
            res.append(str(bit))

    dfs(0)

    res.reverse()
    print("0" * (n - 1) + "".join(res))

main()
