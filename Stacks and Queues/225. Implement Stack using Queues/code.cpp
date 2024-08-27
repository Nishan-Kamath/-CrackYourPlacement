class MyStack {
public:
    queue<int> qu;
    queue<int> helper;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!qu.empty()){
            helper.push(qu.front());
            qu.pop();
        }
        qu.push(x);
        while(!helper.empty()){
            qu.push(helper.front());
            helper.pop();
        }
    }
    
    int pop() {
        int res = qu.front();
        qu.pop();
        return res;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
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