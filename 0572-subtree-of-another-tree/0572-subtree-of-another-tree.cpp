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

    bool isIdentical(TreeNode* r1, TreeNode* r2){
        if(r1==NULL&&r2==NULL)return true;
        if(!r1||!r2) return false;

        if(r1->val != r2->val){
            return false;
        }

        return isIdentical(r1->left, r2->left)&&isIdentical(r1->right, r2->right);
    }

    

    bool isSubtree(TreeNode* root, TreeNode* subRoot){

        if(root==NULL&&subRoot==NULL)return true;

        if(!root||!subRoot) return false; 

        if(root->val == subRoot->val){
            if(isIdentical(root, subRoot))
                return true;
        }

        int leftSubtree = isSubtree(root->left, subRoot);

        if(!leftSubtree)
            return isSubtree(root->right, subRoot);

        return true;

    }
};