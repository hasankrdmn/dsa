class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, data: int) -> None:
        self.queue.append(data)

    def dequeue(self) -> int:
        return self.queue.pop(0)
    
    def size(self) -> int:
        return len(self.queue)
    
    def empty(self) -> bool:
        return self.size() == 0
    
    def show(self) -> None:
        print(self.queue)
