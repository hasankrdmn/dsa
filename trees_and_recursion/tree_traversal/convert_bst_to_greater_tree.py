def convertBST(root):
    sum_values = 0
    def traverse(node):
        if not node:
            return
        nonlocal sum_values
        if (node.right):
            traverse(node.right)
        tmp = node.val
        node.val += sum_values
        sum_values += tmp
        if (node.left):
            traverse(node.left)
    traverse(root)
    return root
