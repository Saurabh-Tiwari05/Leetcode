class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        int a=n;
        while(a>0){
            int temp=a%10;
            vec.push_back(temp);
            a=a/10;
        }
        sort(vec.begin(),vec.end());
        int k=vec.size();
        return vec[k-1]*vec[k-2];
    }
};