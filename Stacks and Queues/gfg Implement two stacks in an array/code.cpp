class twoStacks {
  public:
    vector<int> st1;
    vector<int> st2;
        
    twoStacks() {}
        
    // Function to push an integer into the stack1.
    void push1(int x) {
        st1.push_back(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        st2.push_back(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(st1.empty())
            return -1;
        int popped_item =  st1.back();
        st1.pop_back();
        return popped_item;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(st2.empty())
            return -1;
        int popped_item =  st2.back();
        st2.pop_back();
        return popped_item;
    }
};