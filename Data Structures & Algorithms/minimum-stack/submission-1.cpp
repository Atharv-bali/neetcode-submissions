class MinStack {
public:

    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) { //O(1)
        st.push(val);
        if(minStack.empty())
            minStack.push(val);
        else if(minStack.top()>=val)
            minStack.push(val);
    }
    
    void pop() { //O(1)
        if(!st.empty()) {
            int val = st.top();
            if(minStack.top()==val)
                minStack.pop();
            st.pop();
        }
    }
    
    int top() { //O(1)
        return st.top();
    }
    
    int getMin() { //O(1)
        return minStack.top();
    }
};
//Time complexity: O(1)
//Space complexity: O(n)