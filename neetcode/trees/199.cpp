#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

vector<int> rightSideView(TreeNode* root){
    vector<int> rview;
    queue<TreeNode*> q;

    if (root == nullptr) return rview;
    q.push(root);

    while(!q.empty()){
        int lvlsize = q.size();

        for (int i=0; i < lvlsize; i++){
            TreeNode* curr = q.front();
            q.pop();

            if (i == lvlsize - 1){
                rview.push_back(curr->val);
            }

            if (curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
    }
    return rview;
}