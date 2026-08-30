class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0,prod=1;
        int a=n;
        while(a>0){
            long long temp=a%10;
            sum+=temp;
            prod*=temp;
            a=a/10;
        }
        sum+=prod;
        return n%sum==0?true:false;
    }
};