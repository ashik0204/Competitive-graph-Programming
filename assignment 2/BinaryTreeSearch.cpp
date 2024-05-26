class Solution {
    public:
        vector<vector<int>> BFS(TreeNode* root,int val) {
        root=searchBST(root,val);
        vector<vector<int>> ans;
        if(root != NULL) {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                int size = q.size();
                vector<int> v;
                for(int i = 0; i < size; i++) {
                    TreeNode* temp = q.front();
                    q.pop();
                    v.push_back(temp->val);
                    if(temp->left) { q.push(temp->left); }
                    if(temp->right) { q.push(temp->right); }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
    private:
        TreeNode* searchBST(TreeNode* root, int val) {
            if(root==NULL){
                return (NULL);
            }
            if(root->val==val){
                return (root);
            }
            return max(searchBST(root->right,val),searchBST(root->left,val));
        }
};
