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
        int ans=0;
    void solve(TreeNode* root,int i){
        if(!root){
            ans=max(ans,i);
            return;
        }
      
            solve(root->left,i+1);
            solve(root->right,i+1);
        
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        solve(root,ans);
        return ans;
    }
};