class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int m=s.length();
        int i=m-2;
        while(i>=0 && s[i]>=s[i+1])i--;

        if(i<0)return -1;

        for(int j=m-1;j>=0;j--){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
                break;
            }
        }
        reverse(s.begin()+i+1,s.end());
        long long val=stoll(s);
        return val>INT_MAX?-1:val;
    }
};