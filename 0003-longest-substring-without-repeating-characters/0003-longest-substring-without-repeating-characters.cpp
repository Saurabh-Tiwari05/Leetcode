class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n<=1)return n;
        unordered_map<char,int> lastseen;
        int ans=0;
        int l=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(lastseen.count(c) && lastseen[c]>=l){
                l=lastseen[c]+1;
            }
            lastseen[c]=i;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};