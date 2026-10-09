#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDia;

int diameterOfBinaryTree(TreeNode* root){
    maxDia = 0;
    maxDepth(root);
    return maxDia;
}

int maxDepth(TreeNode* root){
    if (root == nullptr) return 0;

    int l_height = maxDepth(root->left);
    int r_height = maxDepth(root->right);
    maxDia = std::max(maxDia, l_height + r_height);
    return std::max(l_height, r_height) + 1;
}