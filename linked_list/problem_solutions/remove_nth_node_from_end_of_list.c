struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p1 = head, *p2 = head;

    while (n > 0 && p2)
    {
        p2 = p2 -> next;
        n--;
    }

    while (p2 && p2 -> next)
    {
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    if (p1 == head && !p2)
    {
        return (p1 -> next);
    }
    p1 -> next = p1 -> next -> next;

    return (head);
}