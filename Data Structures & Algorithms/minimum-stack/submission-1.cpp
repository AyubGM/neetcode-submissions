class MinStack {
    std::stack<std::pair<int, int>> st;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            auto [first, min] = st.top();
            if (val < min) {
                st.push({val, val});
            } else {
                st.push({val, min});
            }
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};
