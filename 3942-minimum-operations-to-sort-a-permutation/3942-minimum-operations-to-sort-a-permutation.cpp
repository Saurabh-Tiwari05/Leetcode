class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        int pos0 = 0;

        while (nums[pos0] != 0)
            pos0++;

        bool asc = true, desc = true;

        for (int i = 0; i < n; i++) {

            if (nums[(i + 1) % n] != (nums[i] + 1) % n)
                asc = false;

            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n)
                desc = false;
        }

        int ans = INT_MAX;

        if(asc) {

            int k = pos0;

            ans = min(ans, min(k, 2 + min(k, n - k)));
        }

        if (desc) {

            int k = (n - 1 - pos0 + n) % n;

            ans = min(ans, 1 + min(k, n - k));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};