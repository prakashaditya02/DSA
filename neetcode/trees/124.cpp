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
int maxSum;

int dfs(TreeNode* root){
    if (root == nullptr) return 0;

    int left = std::max(0, dfs(root->left));
    int right = std::max(0, dfs(root->right));
    maxSum = std::max({maxSum, left + right + root->val, left + root->val, right + root->val});
    return root->val + std::max(left, right);
}

int maxPathSum(TreeNode* root){
    maxSum = INT_MIN;
    dfs(root);
    return maxSum;
}