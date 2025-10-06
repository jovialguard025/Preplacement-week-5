class Node:
    def __init__(self, new_data):
        self.data = new_data
        self.next = None

class myStack:
    def __init__(self):
        self.top = None
        self.count = 0

    def isEmpty(self):
        return self.top is None

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.top
        self.top = new_node
        self.count += 1

    def pop(self):
        if self.isEmpty():
            return
        self.top = self.top.next
        self.count -= 1

    def peek(self):
        if self.isEmpty():
            return -1
        return self.top.data

    def size(self):
        return self.count
