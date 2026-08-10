class Solution {
public:
    void solve(int index, string s, vector<string>& path,
               vector<vector<string>>& result) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (ispalin(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, result);
                path.pop_back();
            }
        }
    }
    bool ispalin(string s, int start, int end) { 
        while (start < end) { 
            if (s[start++] != s[end--]) return false; 
        } 
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(0, s, path, result);
        return result;
    }
};