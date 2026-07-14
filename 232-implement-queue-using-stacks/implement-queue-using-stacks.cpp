class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        // Move all elements to helper stack
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        // Pop the top element from helper stack (which is the front of the queue)
        int x = helper.top();
        helper.pop();
        
        // Push all elements back to the original stack
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {
        // Move all elements to helper stack
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        // Peek the top element of helper stack (which is the front of the queue)
        int x1 = helper.top();
        
        // Push all elements back to the original stack
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x1;
    }
    
    bool empty() {
        // If the stack is empty, then the queue is empty
        return st.empty();
    }
};