class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeNthFromEnd(head, n: int):
    p1 = head
    p2 = head

    while (n > 0 and p2):
        p2 = p2.next
        n -= 1
    
    while (p2 and p2.next):
        p1 = p1.next
        p2 = p2.next

    if (p1 == head) and not p2:
        return head.next
    
    p1.next = p1.next.next
    return head