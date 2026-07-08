class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int>ans;
        bool flag;

        for(int i=0;i<n;i++)
        {
            flag = false;

            for(int j=i+1;j<n;j++)
            {
                if(j > i && prices[i] >= prices[j])
                {
                    ans.push_back(prices[i]-prices[j]);
                    flag = true;
                    break;
                }
            }

            if(!flag)
            ans.push_back(prices[i]);
        }

        return ans;
    }
};