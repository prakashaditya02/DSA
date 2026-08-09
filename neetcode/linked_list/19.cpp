struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode *p1 = &dummy, *p2 = &dummy;

    for (int i = 0; i < n+1; i++) p1 = p1->next;

    while (p1 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    p2->next = p2->next->next;
    return dummy.next;
}