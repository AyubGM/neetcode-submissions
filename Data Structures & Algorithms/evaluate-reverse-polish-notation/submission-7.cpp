class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for (string& s : tokens)
        {
            if (s == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = a + b;
                st.push(c); 
            } else if (s == "-") 
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = b - a;
                st.push(c);
            } else if (s == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = a * b;
                st.push(c);
            } else if (s == "/") 
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = std::floor(b / a);
                st.push(c);
            } else
            {
                st.push(std::stoi(s));
            }
        }

        return st.top();
    }
};
