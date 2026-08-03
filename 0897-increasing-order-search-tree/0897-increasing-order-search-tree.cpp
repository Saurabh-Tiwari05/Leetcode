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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        int n=result.size();
        sort(result.begin(),result.end());
        TreeNode *prev=new TreeNode(result[0]),*ans=prev;;
        int i=1;
        while(i<n){
            TreeNode *temp=new TreeNode(result[i]);
            prev->right=temp;
            prev=temp;
            i++;
        }

        return ans;
    }
};