class Stack:
    def __init__(self):
        self.stack = []

    def push(self, data: int) -> None:
        self.stack.append(data)
    
    def pop(self) -> int:
        return self.stack.pop()

    def size(self) -> int:
        return len(self.stack)
    
    def empty(self) -> bool:
        return self.size() == 0

    def show(self) -> None:
        print(self.stack)
