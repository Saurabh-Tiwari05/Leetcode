class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        long long mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int low=0,high=n-1;
        long long sum=0;
        while(low<high)
            {
                sum+= __gcd(prefixGcd[low],prefixGcd[high]);
                low++;
                high--;
            }
        return sum;
    }
};