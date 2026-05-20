import sys
input = sys.stdin.readline

def main():
    n = int(input())
    list_a = list(map(int, input().split()))

    print(abs(sum(list_a) - int(n * (n + 1) // 2)))

main()