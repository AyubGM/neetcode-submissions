class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        std::stack<int> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prevDay = st.top();
                st.pop();

                res[prevDay] = i - prevDay;

            }

            st.push(i);
        }

  

        return res;
       
    }
};
