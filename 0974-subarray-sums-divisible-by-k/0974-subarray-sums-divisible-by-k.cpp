class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0;
        int n=nums.size();
        long long sum=0;
        for(auto i:nums){
            sum+=i;
            int mod=(sum%k);
            if(mod<0){
                mod+=k;
            }
            if(mp.find(mod)!=mp.end()){
                ans+=mp[mod];
            }
            mp[mod]++;
        }
        return ans;
    }
};