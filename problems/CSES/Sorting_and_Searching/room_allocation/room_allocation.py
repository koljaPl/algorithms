import sys
from heapq import heappush, heappop
# sys.setrecursionlimit(200000)

input = sys.stdin.readline

# Russian:
"""
Этот код полностью логически правильный, но изза особености Python (в особенности его скорости)
это решение не пройдет, и как мне кажеться, найти решение на Python которое пройдет тесты будет
весьма проблематично.
"""

# English:
"""
This code is entirely logically correct, but due to a peculiarity of Python (particularly its speed),
this solution will not pass the tests, and I think it will be quite difficult to find a Python solution 
that will pass the tests.
"""

def main():
    n = int(input())

    customers = []
    for i in range(n):
        a, b = map(int, input().split())
        customers.append((a, b, i))

    customers.sort()

    rooms = []

    allocation_example = [0] * n
    room_count = 0

    for arrival, departure, idx in customers:
        if rooms and rooms[0][0] < arrival:
            last_departure, room_id = heappop(rooms)
        else:
            room_count += 1
            room_id = room_count

        allocation_example[idx] = room_id
        heappush(rooms, (departure, room_id))

    print(room_count)
    print(*allocation_example)

main()
