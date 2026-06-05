import sys
input = sys.stdin.readline

def main():
    s = input()

    left_parts = []
    mid = ""

    for i in range(65, 91):
        char = chr(i)
        count = s.count(char)

        if count == 0:
            continue

        if count % 2 != 0:
            if mid:
                print("NO SOLUTION")
                return
            mid = char

        left_parts.append(char * (count // 2))

    left_str = "".join(left_parts)

    print(left_str + mid + left_str[::-1])

main()
