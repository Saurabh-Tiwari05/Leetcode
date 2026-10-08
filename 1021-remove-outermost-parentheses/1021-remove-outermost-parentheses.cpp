class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans = "";
        stack<char> stk;
        for (auto i : s) {
            if(i=='('){
                if(!stk.empty()){
                    ans.push_back(i);
                }
                stk.push(i);
            }
            else if(i==')'){
                stk.pop();
                if(!stk.empty()){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};