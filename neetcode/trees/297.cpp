#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root){
    if (root == nullptr) return "-1001";
    string curr = std::to_string(root->val); 
    string left = serialize(root->left);
    string right = serialize(root->right);
    return curr + "," + left + "," + right;
}

TreeNode* buildTree(vector<int>& preorder, int& idx){
    if (preorder[idx] == -1001){
        idx++;
        return nullptr;
    }
    TreeNode* newNode = new TreeNode(preorder[idx++]);
    newNode->left = buildTree(preorder, idx);
    newNode->right = buildTree(preorder, idx);
    return newNode;
}

TreeNode* deserialize(string data){
    vector<int> preord;
    string temp = "";
    for (auto i : data){
        if (i == ','){
            preord.push_back(stoi(temp));
            temp = "";
            continue;
        } else {
            temp += i;
        }
    }
    if (!temp.empty()) preord.push_back(stoi(temp));
    int idx = 0;
    return buildTree(preord, idx);
}