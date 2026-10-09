#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool flag;

int maxDepth(TreeNode* root){
    if (root == nullptr) return 0;

    int l = maxDepth(root->left) + 1;
    int r = maxDepth(root->right) + 1;

    if (abs(l-r) > 1) flag = false;
    return std::max(l, r);
}

bool isBalanced(TreeNode* root){
    flag = true;
    maxDepth(root);
    return flag;
}
