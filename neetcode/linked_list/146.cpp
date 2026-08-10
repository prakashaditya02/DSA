#include <unordered_map>
struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next) : key(x), val(0), next(next) {}
};

using namespace std;

class LRUCache {
public:
    unordered_map<int, ListNode*> Dict;
    int cap;
    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();

    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insert(ListNode* node) {
        ListNode* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void removeLast() {
        ListNode* least = tail->prev;
        Dict.erase(least->key);
        remove(least);
    }

    int get(int key) {
        auto it = Dict.find(key);
        if (it != Dict.end()) {
            remove(it->second);
            insert(it->second);
            return Dict[key]->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = Dict.find(key);
        if (it != Dict.end()) remove(it->second);
        else if (Dict.size() == cap) removeLast();
        ListNode* N = new ListNode(key, value);
        Dict[key] = N;
        insert(N);
    }
};