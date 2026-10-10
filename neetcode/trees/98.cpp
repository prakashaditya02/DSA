#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root, long long lb, long long ub){
    if (root == nullptr) return true;

    if (!((lb < root->val) && (root->val < ub))) return false;

    if (!dfs(root->left, lb, root->val)) return false;
    if (!dfs(root->right, root->val, ub)) return false;

    return true;
}

bool isValidBST(TreeNode* root) {
    long long lb = LONG_LONG_MIN;
    long long ub = LONG_LONG_MAX;
    return dfs(root, lb, ub);
}