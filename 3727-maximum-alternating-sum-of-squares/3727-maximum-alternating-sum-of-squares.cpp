class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0,j=n-1;
        bool flag=true;
        long long score=0;
        while(i<=j){
            if(i==j){
                score+=(long long)nums[i]*nums[i];
                break;
            }
            else{
            long long k=(long long)nums[i]*nums[i];
            long long l=(long long)nums[j]*nums[j];
            score=score+k-l;
            i++;
            j--;
            }
            
        }
        return score;
    }
};