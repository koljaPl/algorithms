# Linked List

# Time Complexity:
# append():     O(1)
# prepend():    O(1)
# delete():     O(n)
# find():       O(n)
# get_size():   O(1)
#
# Space Complexity:
# Memory:       O(n)

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    # O(1)
    def append(self, data):
        node = Node(data)

        if not self.head:
            self.head = self.tail = node
        else:
            self.tail.next = node
            self.tail = node

        self.size += 1

    # O(1)
    def prepend(self, data):
        node = Node(data)

        if not self.head:
            self.head = self.tail = node
        else:
            node.next = self.head
            self.head = node

        self.size += 1

    # O(n)
    def delete(self, data):
        if not self.head:
            return

        if self.head.data == data:
            self.head = self.head.next
            self.size -= 1

            if not self.head:
                self.tail = None
            return

        prev = self.head
        curr = self.head.next

        while curr:
            if curr.data == data:
                prev.next = curr.next

                if curr == self.tail:
                    self.tail = prev

                self.size -= 1
                return

            prev, curr = curr, curr.next

    # O(n)
    def find(self, data):
        curr = self.head

        while curr:
            if curr.data == data:
                return curr
            curr = curr.next

        return None

    def get_size(self):
        return self.size