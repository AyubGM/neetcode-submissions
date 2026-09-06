class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> temps(temperatures.size() ,0);
        std::stack<int> maxSt;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!maxSt.empty() && temperatures[maxSt.top()] < temperatures[i])
            {
                int prev_index = maxSt.top();
                maxSt.pop();
                temps[prev_index] = i - prev_index;
            }

            maxSt.push(i);
        }

        return temps;
    }
};
