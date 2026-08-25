class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hashset;
        for(auto i:nums){
            hashset.insert(i);
        }
        int a=k;
        while(1){
            if(hashset.find(a)==hashset.end()){
                return a;
            }
            else{
                a+=k;
            }
        }
        return -1;
    }
};