class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mx1 = INT_MIN, lx1 = INT_MAX;
        int mx2 = INT_MIN, lx2 = INT_MAX;
        int mx3 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = nums[i];
            } else if (nums[i] > mx2) {
                mx3 = mx2;
                mx2 = nums[i];
            } else if (nums[i] > mx3) {
                mx3 = nums[i];
            }

            if (nums[i] < lx1) {
                lx2 = lx1;
                lx1 = nums[i];
            } else if (nums[i] < lx2) {
                lx2 = nums[i];
            }
        }

        int ans1 = (mx1) * (mx2) * (mx3);
        int ans2 = lx1 * lx2 * mx1;
        int ans = max(ans1, ans2);
        return ans;
    }
};