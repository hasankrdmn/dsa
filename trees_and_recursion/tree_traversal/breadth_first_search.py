class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root_node = None
    
    def insert(self, val):
        new_node = Node(val)
        
        if (self.root_node is None):
            self.root_node = new_node
            return True
        controller = self.root_node
        while True:
            if (val < controller.data):
                if controller.left is None:
                    controller.left = new_node
                    return True
                controller = controller.left
                continue
            if (val > controller.data):
                if controller.right is None:
                    controller.right = new_node
                    return True
                controller = controller.right
                continue
            else:
                return False
    
    def BFS(self):
        controller = self.root_node
        result = []
        values = []
        values.append(controller)

        while len(values) > 0:
            controller = values.pop(0)
            result.append(controller.data)
            if controller.left is not None:
                values.append(controller.left)
            if controller.right is not None:
                values.append(controller.right)
        return result
