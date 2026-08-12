class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;
            int start = i;
            while (i < n && s[i] != ' ') {
                i++;
            }
            string word = s.substr(start, i - start);
            reverse(word.begin(), word.end());
            if (ans.empty()) {
                ans += word;
            } else {
                ans += " " + word;
            }
        }

        return ans;
    }
};
