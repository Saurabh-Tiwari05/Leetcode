class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int cnt_zero=0;
        int l=0,r=0;
        while(r<n){
            if(nums[r]==0){
                cnt_zero++;
                if(cnt_zero>k){
                    while(nums[l]!=0){
                        l++;
                    }
                    l++;
                    cnt_zero--;
                }
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};