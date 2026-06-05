import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    res = [n]

    while n != 1:
        if n % 2 == 0:
            n //= 2
            res.append(int(n))
        else:
            n = (n * 3) + 1
            res.append(int(n))

    print(*res)

main()