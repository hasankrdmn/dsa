class Stack:
    def __init__(self):
        self.stack = []

    def push(self, data: int) -> None:
        self.stack.append(data)
    
    def pop(self) -> int:
        return self.stack.pop()

    def show(self) -> None:
        if self.stack == []: return
        print(self.stack)

# myStack = Stack()
# myStack.push(1)
# myStack.push(2)
# myStack.pop()
# myStack.push(3)
# myStack.push(4)
# myStack.pop()
# myStack.push(5)
# myStack.show()