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

class Info{
public:
    bool isBST;
    int mini;
    int maxi;
    int sum;

    Info(bool isBST, int mini, int maxi, int sum){
        this->isBST = isBST;
        this->mini = mini;
        this->maxi = maxi;
        this->sum = sum;
    }
}; 

class Solution {
public:
    
    Info* maxBST(TreeNode* root){
            if(!root){
                return new Info(true, INT_MAX, INT_MIN, 0);
            }

            Info* lI = maxBST(root->left);
            Info* rI = maxBST(root->right);
            int currMin = min(root->val, min(lI->mini, rI->mini));
            int currMax = max(root->val, max(lI->maxi, rI->maxi));
            int currSum = root->val+lI->sum+rI->sum;

            if(lI->isBST && rI->isBST
            && root->val>lI->maxi && root->val<rI->mini){
            
                maxSum = max(maxSum, currSum);

                return new Info(true, currMin, currMax, currSum);
            }
            return new Info(false, currMin, currMax, currSum);
    }

    int maxSum = 0;

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        maxBST(root);

        return maxSum;
    }
};  