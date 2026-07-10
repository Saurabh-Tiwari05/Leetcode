class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //Approach1: with stack
        // stack<int> stk;
        // int n=pushed.size();
        // int k=0;
        // for(int i=0;i<n;i++){
        //     stk.push(pushed[i]);
        //    while(!stk.empty() && stk.top()==popped[k]){
        //         stk.pop();
        //         k++;
        //    }
        // }
        // return stk.empty();

        //Approach2 without using extra stack
        int i=0, j=0;
        for(int x:pushed){
            pushed[i++]=x;
            while(i>0 && pushed[i-1]==popped[j]){
                --i;
                ++j;
        }
        }
        return i==0;
    }
};