class MinStack {
    stack<int>st;
public:
    MinStack() {
        mini=LLMAX;
    }
    
    void push(int value) {
       if(st.empty()){
        st.push(value);
        mini=value;
       }
       else {
       if(!st.empty()&&mini>value){
        mini=value;
        st.push(2*LL*value-mini);
       }
       else{
        st.push(value);
       }
       }
    }
    
    void pop() {
        if(st.empty()) return;
        int x=st.top();
        st.pop();
        if(x<mini){
            mini=2*LL*mini-x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        int x=st.top();
        if(x<mini){
            return (int) mini;
        }
        else{
            return (int)x;
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */