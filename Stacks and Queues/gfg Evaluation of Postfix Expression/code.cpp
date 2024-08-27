class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int applyOperation(int op1, int op2 ,char ch){
        int result;
        switch(ch){
            case '+': 
                    return op1 + op2;
                
            case '-': 
                    return op1 - op2;
            case '*': 
                    return op1 * op2;
            case '/': 
                if (op2 == 0) {
                    throw runtime_error("Division by zero");
                }
                return op1 / op2;
            case '%': 
                    return op1 % op2;
        }
        return result;
    }
    int evaluatePostfix(string S)
    {
       stack<int> st;
       for(char ch : S){
           if(isdigit(ch)){
               st.push(ch-'0');
           }else{
               int op2 = st.top();st.pop();
               int op1 = st.top();st.pop();
               
               int result = applyOperation(op1,op2,ch);
               st.push(result);
           }
       }
       return st.top();
    }
};