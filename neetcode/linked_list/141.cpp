struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) return true;
    }
    return false;
}