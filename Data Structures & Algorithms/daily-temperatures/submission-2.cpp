class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        std::stack<int> st;

        // for(int i = 0; i < temperatures.size(); i++)
        // {
        //     while(!st.empty() && temperatures[i] > temperatures[st.top()])
        //     {
        //         int prevDayIndex =  st.top();
        //         st.pop();

        //         res[prevDayIndex] = i - prevDayIndex;
        //     }
        //     st.push(i);
        // }

        for(size_t i{}; i < temperatures.size() - 1; ++i)
        {
            int temp = temperatures[i];
            int j = i + 1;
            int h = 1;
            bool found_warmer = false;
            while ( j < temperatures.size() && temp >= temperatures[j])
            {
                h++;
                j++;
            }

            if (j < temperatures.size()) {
                found_warmer = true;
            }

            res[i] = found_warmer ? h : 0;
        }

        return res;
       
    }
};
