class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
    pointerA = headA
    pointerB = headB

    while (pointerA != pointerB):
        pointerA = pointerA.next if pointerA != None else headB
        pointerB = pointerB.next if pointerB != None else headA
    
    return pointerA