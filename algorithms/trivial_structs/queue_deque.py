# Queue / Deque:
# Time Complexity:
# Enqueue:      O(1)
# Dequeue:      O(1)
# Peek:         O(1)
#
# append():     O(1)
# appendleft(): O(1)
# pop():        O(1)
# popleft():    O(1)
# peek():       O(1)
#
# Space Complexity:
# Memory:       O(n)

class Deque:
    def __init__(self, block_size=4):
        self.block_size = block_size
        self.blocks = [[]]

    def append(self, value):
        if len(self.blocks[-1]) == self.block_size:
            self.blocks.append([])

        self.blocks[-1].append(value)

    def appendleft(self, value):
        if len(self.blocks[0]) == self.block_size:
            self.blocks.insert(0, [])

        self.blocks[0].insert(0, value)

    def pop(self):
        if not self.blocks:
            raise IndexError

        val = self.blocks[-1].pop()

        if not self.blocks[-1]:
            self.blocks.pop()

        return val

    def popleft(self):
        if not self.blocks:
            raise IndexError

        val = self.blocks[0].pop(0)

        if not self.blocks[0]:
            self.blocks.pop(0)

        return val

    def peek_left(self):
        return self.blocks[0][0]

    def peek_right(self):
        return self.blocks[-1][-1]

class Queue:
    def __init__(self):
        self.data = Deque()

    def enqueue(self, value):
        self.data.append(value)

    def dequeue(self):
        return self.data.popleft()

    def peak(self):
        return self.data.peek_left()

# Nothing out of the ordinary—it’s a standard list with FIFO by default,
# although you can do whatever you like with a deque via collections.
# A VERY HANDY STRUCTURE!
