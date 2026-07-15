class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0,min, sumeven=0,i;
          for (int i=0;i<n;i++) {
            sumodd+=2*i+1;
        }
        for (int i=1;i<=n;i++) {
            sumeven+=2*i;
        }
        if(sumodd<sumeven)
        { min = sumodd;}
        else
        { min = sumeven;}
        for(int i=min; i>=1; i--)
        {
            if(sumodd%i==0 && sumeven%i==0)
            {
                return i;
            }
        }
    return 1;
    }
};