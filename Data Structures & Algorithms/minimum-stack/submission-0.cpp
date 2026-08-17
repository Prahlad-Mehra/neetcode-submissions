class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(!minStack.empty()) minStack.push(min(val, minStack.top()));
        else minStack.push(val);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
