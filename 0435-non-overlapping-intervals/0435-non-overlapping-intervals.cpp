class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int ans=0;
        int a=intervals[0][0],b=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<b){
                ans++;
            }
            else{
                b=intervals[i][1];
            }
        }
        return ans;
    }
};