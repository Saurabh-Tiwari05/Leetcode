class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            bool destroy = false;
            while (!stk.empty() && stk.top() > 0 && asteroids[i] < 0) {
                if (stk.top() < abs(asteroids[i])) {
                    stk.pop();
                } else if (stk.top() == abs(asteroids[i])) {
                    stk.pop();
                    destroy = true;
                    break;
                } else {
                    destroy = true;
                    break;
                }
            }
            if (!destroy) {
                stk.push(asteroids[i]);
            }
        }
        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
    }
};