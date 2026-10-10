#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int counter = 0;
int val;

void inorder(TreeNode* root, int k){
    if (root == nullptr) return;
    if (counter == k) return;

    inorder(root->left, k);
    if (counter == k) return;

    if (++counter == k){
        val = root->val;
        return;
    }

    inorder(root->right, k);
    return;
}

int kthSmallest(TreeNode* root, int k){
    counter = 0;
    inorder(root, k);
    return val;
}