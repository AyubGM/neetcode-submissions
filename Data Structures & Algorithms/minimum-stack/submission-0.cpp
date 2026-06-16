class MinStack {
    std::vector<std::pair<int,int>>  m_Stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(m_Stack.empty())
        {
            m_Stack.push_back({val,val});
        } else 
        {
            int min = std::min(m_Stack.back().second, val);
            m_Stack.push_back({val,min});
        }


    }
    
    void pop() {
        m_Stack.pop_back();
    }
    
    int top() {
        return m_Stack.back().first;
    }
    
    int getMin() {
        return m_Stack.back().second;
    }
};
