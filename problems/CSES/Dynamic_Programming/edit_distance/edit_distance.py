import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    a = str(input())
    b = str(input())

    n, m = len(a), len(b)

    previous = list(range(m + 1))
    current = [0] * (m + 1)

    for i in range(1, n + 1):
        current[0] = i

        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                current[j] = previous[j - 1]
            else:
                remove_char = previous[j]
                add_char = current[j - 1]
                replace_char = previous[j - 1]

                current[j] = 1 + min(
                    remove_char,
                    add_char,
                    replace_char
                )

        previous, current = current, previous

    print(previous[m])

main()
