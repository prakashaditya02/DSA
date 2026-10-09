#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> lvl;
    queue<TreeNode*> q;

    if (root != nullptr) q.push(root);
    else return lvl;

    while(!q.empty()){
        int lvlsize = q.size();
        vector<int> l;
        for (int i=0; i < lvlsize; i++){
            TreeNode* curr = q.front();
            l.push_back(curr->val);
            q.pop();

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        lvl.push_back(l);
    }
    return lvl;
}