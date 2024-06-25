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
    int sumOfLeftLeaves(TreeNode* root,int i=0) {
        int val=0;
        if(!root->left&&!root->right){
            val+=i*root->val;
            return val;
        }

        if(root->right){
            val+=sumOfLeftLeaves(root->right,0);
        }
        if(root->left){
            val+=sumOfLeftLeaves(root->left,1);
        }
        return val;
    }
};
