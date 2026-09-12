class Solution {
public:
    string reverseWords(string s) {
        int n=s.length(),i=0;
        while(i<n){
            int j=i;
            while(j!=n-1 && s[j+1]!=' ')j++;
            int k=j;
            while(i<j){
                swap(s[i++],s[j--]);
            }
            i=k+2;
        }
        return s;
    }
};