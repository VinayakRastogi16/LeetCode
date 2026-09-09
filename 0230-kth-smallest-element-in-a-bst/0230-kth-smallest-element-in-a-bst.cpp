/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void postOrder(TreeNode* root, vector<int>& nodes){
        if(!root)return;

        postOrder(root->left, nodes);
        nodes.push_back(root->val);
        postOrder(root->right, nodes);
        
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int> nodes;

        postOrder(root, nodes);

        return nodes[k-1];
    }
};