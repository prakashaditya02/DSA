struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* c1 = l1, *c2 = l2, *r = result;
    int carry = 0;

    while (c1 != nullptr && c2 != nullptr) {
        ListNode* sum = new ListNode(c1->val + c2->val + carry);

        if (sum->val > 9){
            carry = sum->val/10;
            sum->val = sum->val%10;
        } else carry = 0;

        r->next = sum;
        c1 = c1->next;
        c2 = c2->next;
        r = r->next;
    }

    while (c1 != nullptr) {
        ListNode* sum = new ListNode(c1->val + carry);
        if (sum->val > 9){
            carry = sum->val/10;
            sum->val = sum->val%10;
        } else carry = 0;

        r->next = sum;
        c1 = c1->next;
        r = r->next;
    } 
    
    while (c2 != nullptr) {
        ListNode* sum = new ListNode(c2->val + carry);
        if (sum->val > 9){
            carry = sum->val/10;
            sum->val = sum->val%10;
        } else carry = 0;

        r->next = sum;
        c2 = c2->next;
        r = r->next;
    }

    if (carry>0) {
        ListNode* last = new ListNode(carry);
        r->next = last;
    }

    return result->next;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* c1 = l1, *c2 = l2, *r = result;
    int carry = 0;

    while (c1 != nullptr || c2 != nullptr || carry) {
        int sum = carry;
        if (c1) {
            sum += c1->val;
            c1 = c1->next;
        }
        if (c2) {
            sum += c2->val;
            c2 = c2->next;
        }
        carry = sum/10;
        sum = sum%10;
        r->next = new ListNode(sum);
        r = r->next;
    }

    return result->next;
}
};