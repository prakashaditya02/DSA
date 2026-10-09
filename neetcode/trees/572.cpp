#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTrees(TreeNode* p, TreeNode* q){
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    bool l = isSameTrees(p->left, q->left);
    if (!l) return false;
    bool r = isSameTrees(p->right, q->right);
    if (!r) return false;

    return true;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr && subRoot == nullptr) return true;
    else if (root == nullptr) return false;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);

        if (isSameTrees(curr, subRoot)) return true;
    }
    return false;
}