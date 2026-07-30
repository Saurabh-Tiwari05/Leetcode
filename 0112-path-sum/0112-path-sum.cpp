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
    void solve(TreeNode *root ,int sum,bool &flg){
        sum-=root->val;
        if(root->left){
            solve(root->left,sum,flg);
            if(flg){
                return;
            }
        }
        if(root->right){
            solve(root->right,sum,flg);
            if(flg)
            return;
        }
        if(!root->left && !root->right && sum==0){
            flg=true;
            return;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        bool flg=false;
        solve(root,targetSum,flg);
        return flg;
    }
};

// class Solution {
// public:
//     void solve(TreeNode* root,vector<int> curr,vector<vector<int>>&result,int target){
//         if(!root){
//             return;
//         }
//         target-=root->val;
//         curr.push_back(root->val);
//         if(root->left){
//             solve(root->left,curr,result,target);
//         }
//         if(root->right){
//             solve(root->right,curr,result,target);
//         }
//         if(target==0 && (!root->left && !root->right)){
//             result.push_back(curr);
//             return;
//         }
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>> result;
//         vector<int> curr;
//         solve(root,curr,result,targetSum);
//         return result;
//     }
// };