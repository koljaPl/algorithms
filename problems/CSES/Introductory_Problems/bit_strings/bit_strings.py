import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    print(pow(2, n, 10**9 + 7))

main()  