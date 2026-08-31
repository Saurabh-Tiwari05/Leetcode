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
        int maxrec=0;
        for(int i=0;i<n;i++){
            int rec=heights[i]*(nse[i]-pse[i]-1);
            maxrec=max(maxrec,rec);
        }
        return maxrec;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> pref(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                pref[i][j]=sum;
            }
        }

        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(pref[i]));
        }
        return maxArea;
    }
};