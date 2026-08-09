struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode* curr1 = list1;
    ListNode* curr2 = list2;
    ListNode* curr = (curr1->val <= curr2-> val) ? curr1 : curr2;
    ListNode* head = curr;

    if (curr == curr1) curr1 = curr1->next;
    else curr2 = curr2->next;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->val <= curr2->val){
            curr->next = curr1;
            curr1 = curr1->next;
        } else {
            curr->next = curr2;
            curr2 = curr2->next;
        }
        curr = curr->next;
    }
    curr->next = curr1 ? curr1 : curr2;
    return head;
}