class Deque:
    def __init__(self):
        self.deque = []

    def addRight(self, data: int) -> None:
        self.deque.append(data)

    def addLeft(self, data: int) -> None:
        self.deque.insert(0, data)

    def rmvRight(self) -> int:
        return self.deque.pop()
    
    def rmvLeft(self) -> int:
        return self.deque.pop(0)
    
    def size(self) -> int:
        return len(self.deque)

    def empty(self) -> bool:
        return self.size() == 0

    def show(self) -> None:
        print(self.deque)

# myDeque = Deque()
# myDeque.addRight(3)
# myDeque.addLeft(2)
# myDeque.rmvRight()
# myDeque.addLeft(3)
# myDeque.addRight(4)
# myDeque.rmvLeft()
# myDeque.addLeft(1)
# myDeque.show()
