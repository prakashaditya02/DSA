#include <cstddef>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root == nullptr) return root;

    TreeNode* curr = root;

    while(curr != nullptr){
        if ((p->val < curr->val) && (q->val < curr->val)) curr = curr->left;
        else if ((p->val > curr->val) && (q->val > curr->val)) curr = curr->right;
        else break;
    }

    return curr;
}