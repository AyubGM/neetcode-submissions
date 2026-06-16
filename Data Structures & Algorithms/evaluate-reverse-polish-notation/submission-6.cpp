class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for (const auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if (t == "+") st.push(a + b);

                if (t == "-") st.push(b - a);
                if (t == "*") st.push(a * b);
                if (t == "/") st.push(b / a);

            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
