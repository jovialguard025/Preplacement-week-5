class myStack:
    def __init__(self, n):
       
        self.capacity = n
        self.stack = []
    
    def isEmpty(self):
        
        return len(self.stack) == 0

    def isFull(self):
        
        return len(self.stack) == self.capacity

    def push(self, x):
        
        if not self.isFull():
            self.stack.append(x)

    def pop(self):
        
        if not self.isEmpty():
            return self.stack.pop()
        return -1

    def peek(self):
        
        if not self.isEmpty():
            return self.stack[-1]
        return -1s