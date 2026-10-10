#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int prePos, int inStart, int inEnd){
    if (inStart == inEnd) return nullptr;
    TreeNode* newNode = new TreeNode();
    int root = preorder[prePos];
    newNode->val = root;

    int root_idx;
    for (root_idx = inStart; root_idx < inEnd; root_idx++){
        if (inorder[root_idx] == root) break;
    }

    newNode->left = recurse(preorder, inorder, prePos + 1, inStart, root_idx);
    newNode->right = recurse(preorder, inorder, prePos + 1 + (root_idx - inStart), root_idx + 1, inEnd);

    return newNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    return recurse(preorder, inorder, 0, 0, inorder.size());
}