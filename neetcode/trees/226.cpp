struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* newL = root->right;
    TreeNode* newR = root->left;
    root->left = newL;
    root->right = newR;
    
    invertTree(root->left);
    invertTree(root->right);

    return root;
}