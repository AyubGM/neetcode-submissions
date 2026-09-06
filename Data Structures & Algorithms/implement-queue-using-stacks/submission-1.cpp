class MyQueue {
    std::stack<int> in_st;
    std::stack<int> out_st;
public:
    MyQueue() {
        
    }

    void transfer() {
        if (out_st.empty()) {
            while (!in_st.empty()) {
                out_st.push(in_st.top());
                in_st.pop();
            }
        }
    }
    
    void push(int x) {
       in_st.push(x);
    }
    
    int pop() {
        transfer();
        int topVal = out_st.top();
        out_st.pop();
        return topVal;
    }
    
    int peek() {
        transfer();
        return out_st.top();
    }
    
    bool empty() {
        return in_st.empty() && out_st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */