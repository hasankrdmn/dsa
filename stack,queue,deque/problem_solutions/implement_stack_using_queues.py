from queue import Queue

class MyStack:

    def __init__(self):
        self.stack = Queue()
        self.top_val = None

    def push(self, x: int) -> None:
        self.stack.put(x)
        self.top_val = x

    def pop(self) -> int:
        size = self.stack.qsize()
        while size > 1:
            self.push(self.stack.get())
            size -= 1
        return self.stack.get()

    def top(self) -> int:
        if not self.stack.empty():
            return (self.stack.queue[-1])
        return

    def empty(self) -> bool:
        return self.stack.empty()
