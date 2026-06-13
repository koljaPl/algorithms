import sys
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

def main():
    dna = input().strip()

    res = 1
    curr = 1
    for i in range(1, len(dna)):
        if dna[i] == dna[i - 1]:
            curr += 1
        else:
            curr = 1

        res = max(res, curr)

    print(res)

main()
