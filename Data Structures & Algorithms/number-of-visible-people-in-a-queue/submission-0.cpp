class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        std::stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] > heights[st.top()])
            {
                res[st.top()]++;
                st.pop();
            }

            if (!st.empty()) {
                res[st.top()]++; // The taller person on the stack can see the current person too
            }

            st.push(i);
        }

        return res;

    }
};