class Solution {
public:
    void prevsmallerelement(vector<int>& arr, vector<int>& pse, int n) {
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                pse[i] = stk.top();
            }
            stk.push(i);
        }
    }

    void nextsmallerelement(vector<int>& arr, vector<int>& nse, int n) {
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                nse[i] = stk.top();
            }
            stk.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1), nse(n, n);
        prevsmallerelement(heights, pse, n);
        nextsmallerelement(heights, nse, n);
        int maxrec=INT_MIN;
        for(int i=0;i<n;i++){
            int rec=heights[i]*(nse[i]-pse[i]-1);
            maxrec=max(maxrec,rec);
        }
        return maxrec;
    }
};