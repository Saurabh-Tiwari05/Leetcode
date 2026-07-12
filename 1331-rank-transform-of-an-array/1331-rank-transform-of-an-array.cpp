class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int rnk = 1;
        for (int i = 0; i < temp.size(); i++) {
            if (i == 0 || temp[i] != temp[i-1]) {
                mp[temp[i]] = rnk++;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};