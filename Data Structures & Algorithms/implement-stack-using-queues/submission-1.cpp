struct element{
    int id;
    int value;
};

class MyStack {
public:
    queue<element> q1;
    int curr_id;
    MyStack() {
        curr_id = 0;
    }
    
    void push(int x) {
        q1.push({curr_id, x});
        while(q1.front().id < curr_id){
            auto elm = q1.front();
            q1.pop();
            q1.push(elm);
        }

        curr_id++;
    }
    
    int pop() {
        auto top = q1.front();
        q1.pop();
        return top.value;
    }
    
    int top() {
        return q1.front().value;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */