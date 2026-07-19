class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int od = 1, ev = 0;
        while (ev < n && od < n) {
            if (nums[ev] % 2 == 0) {
                ev += 2;
            } else if (nums[od] % 2 != 0) {
                od += 2;
            } else {
                swap(nums[ev], nums[od]);
                ev += 2;
                od += 2;
            }
        }
        return nums;
    }
};