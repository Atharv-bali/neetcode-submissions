class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }

    void push(int x) { //O(1)
        st1.push(x);
    }
    
    int pop() { //O(n)
        while(st1.size()>1) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st1.top();
        st1.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }
    
    int peek() { //O(n)
        while(st1.size()>1) {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st1.top();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }
    
    bool empty() { //O(1)
        if(!st1.empty())
            return false;
        return true;
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