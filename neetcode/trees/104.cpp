#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root){
    if (root == nullptr) return 0;

    std::queue<TreeNode*> q;
    int depth = 0;
    q.push(root);

    while (!q.empty()){
        int lvlsize = q.size();

        for (int i = 0; i < lvlsize; i++){
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        depth += 1;
    }
    return depth;
}

int maxDepthRecursion(TreeNode* root){
    if (root == nullptr) return 0;

    int l = maxDepthRecursion(root->left) + 1;
    int r = maxDepthRecursion(root->right) + 1;
    return std::max(l, r);
}