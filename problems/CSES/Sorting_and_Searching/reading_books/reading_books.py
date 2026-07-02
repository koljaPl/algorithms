import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    books = sorted(list(map(int, input().split())), reverse=True)

    print(max(sum(books), max(books)* 2))

main()
