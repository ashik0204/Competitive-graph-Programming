class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(search(root->left,p,q)&&search(root->right,p,q)){
            return root;
        }
        if((root==p||root==q)&&search(root->right,p,q)){
            return root;
        }
        if(search(root->left,p,q)&&(root==p||root==q)){
            return root;
        }
        if(search(root->left,p,q)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(search(root->right,p,q)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return NULL;
    }
private:
    bool search(TreeNode* root,TreeNode*p,TreeNode*q){
        if(root==NULL){
            return false;
        }
        if(root==p||root==q){
            return true;
        }
        return search(root->right,p,q)||search(root->left,p,q);
    }
};
