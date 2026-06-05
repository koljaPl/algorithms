import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    q = int(input())

    for _ in range(q):
        k = int(input())

        d = 1
        count = 9

        while k > d * count:
            k -= d * count
            d += 1
            count *= 10

        start = 10 ** (d - 1)
        number = start + (k - 1) // d

        digit_index = (k - 1) % d
        print(str(number)[digit_index])

main()
