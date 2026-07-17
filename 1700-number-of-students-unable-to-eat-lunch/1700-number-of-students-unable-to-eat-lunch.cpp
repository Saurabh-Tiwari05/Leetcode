class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> deq;
        int cnt=0,j=0;
        for(int i=0;i<students.size();i++){
            deq.push_back(i);
        }

        while(deq.size()!=cnt){
            if(students[deq.front()]==sandwiches[j]){
            j++;
            cnt=0;
            deq.pop_front();
            }
            else{
                int a=deq.front();
                deq.pop_front();
                deq.push_back(a);
                cnt++;
            }
        }
        return cnt;
    }
};