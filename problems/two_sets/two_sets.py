import sys
input = sys.stdin.readline

def main():
    n = int(input())

    total_sum = (n * (n + 1)) // 2
    if total_sum % 2 != 0:
        print("NO")
        return

    print("YES")

    list_a = []
    list_b = []

    if n % 4 == 0:
        l = 1
        r = n

        while l < r:
            list_a.append(l)
            list_a.append(r)

            list_b.append(l + 1)
            list_b.append(r - 1)

            l += 2
            r -= 2

    else:
        list_a.extend([1, 2])
        list_b.append(3)

        l = 4
        r = n

        while l < r:
            list_a.append(l)
            list_a.append(r)

            list_b.append(l + 1)
            list_b.append(r - 1)

            l += 2
            r -= 2

    print(len(list_a))
    print(*list_a)

    print(len(list_b))
    print(*list_b)


main()
