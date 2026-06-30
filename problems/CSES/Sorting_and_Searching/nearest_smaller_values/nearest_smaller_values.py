import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    n = int(input())
    list_x = list(map(int, input().split()))

    stack = []  # (значение, индекс)

    for i, x in enumerate(list_x, start=1):
        while stack and stack[-1][0] >= x:
            stack.pop()

        if stack:
            print(stack[-1][1], end=" ")
        else:
            print(0, end=" ")

        stack.append((x, i))

main()
