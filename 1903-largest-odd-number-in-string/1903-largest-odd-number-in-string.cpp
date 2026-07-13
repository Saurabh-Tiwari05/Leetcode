class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int left = 0, right = n - 1;

        // while (left < n && (int)num[left] % 2 == 0)
        //     left++;
        while (right >= 0 && (int)num[right] % 2 == 0)
            right--;
        if (left > right)
            return "";

        return num.substr(left, right - left + 1);
    }
};