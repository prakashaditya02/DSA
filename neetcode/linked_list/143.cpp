struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

void reorderList(ListNode* head1) {
    ListNode *curr = head1;
    //find the mid point of list
    int count = 0;
    while (curr != nullptr) {
        curr = curr->next;
        count += 1;
    }
    
    curr = head1;
    for (int i = 1; i <= count/2; i++) curr = curr->next;
    ListNode *head2 = curr->next;
    curr->next = nullptr;

    ListNode *prev = nullptr;
    curr = head2;

    //reverse the second part of list
    while(curr != nullptr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr =  temp;
    }
    head2 = prev;

    //merge both list alternatively
    int i = 1;
    curr = head1;
    ListNode *l1 = head1->next;
    ListNode *l2 = head2;
    while (l1 != nullptr && l2 != nullptr){
        if (i%2  == 0){
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
        i++;
    }

    if (l1 != nullptr) curr->next = l1;
    if (l2 != nullptr) curr->next = l2;
}