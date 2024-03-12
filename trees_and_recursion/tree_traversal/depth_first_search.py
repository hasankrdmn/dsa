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
            
    def DFS(self):
        result = []
        def traverse(node):
            result.append(node.data)        # Pre-order Strategy
            if node.left is not None:
                traverse(node.left)
            # result.append(node.data)       # In-order Strategy
            if node.right is not None:
                traverse(node.right)
            # result.append(node.data)       # Post-order Strategy
        traverse(self.root_node)
        return result
