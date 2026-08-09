#include <cstddef>
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

using namespace std;

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> copy;
    Node* curr = head;
    copy[nullptr] = nullptr;

    while (curr != nullptr) {
        Node* N = new Node(curr->val);
        copy[curr] = N;
        curr = curr->next;
    }

    curr = head;
    while(curr != nullptr) {
        copy[curr]->next = copy[curr->next];
        copy[curr]->random = copy[curr->random];
        curr = curr->next; 
    }

    return copy[head];
}
