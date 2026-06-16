class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        std::stack<int> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prevDayIndex =  st.top();
                st.pop();

                res[prevDayIndex] = i - prevDayIndex;
            }
            st.push(i);
        }

  

        return res;
       
    }
};
