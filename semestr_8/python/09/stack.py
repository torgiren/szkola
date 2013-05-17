#*-* coding: utf8 *-*
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)
        return len(self)

    def pop(self):
        return self.stack.pop()

    def __len__(self):
        return len(self.stack)

    def __str__(self):
        return str(self.stack[::-1])
