class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> mystack;
    MinStack() {
        
    }
    
    void push(int x) {
        int mini;
        if(mystack.empty())
        {
            mini=x;
        }
        else
        {
            mini=min(x,mystack.top().second);
        }
        mystack.push(make_pair(x,mini));
    }
    
    void pop() {
        mystack.pop();
    }
    
    int top() {
        return mystack.top().first;
    }
    
    int getMin() {
        return mystack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */