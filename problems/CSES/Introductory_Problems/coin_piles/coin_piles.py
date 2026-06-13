import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    t = int(input())

    for _ in range(t):
        a, b = map(int, input().split())

        if (a + b) % 3 != 0:
            print("NO")
        else:
            if min(a, b) * 2 >= max(a, b):
                print("YES")
            else:
                print("NO")

main()
