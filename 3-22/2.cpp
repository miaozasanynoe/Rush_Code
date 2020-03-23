class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {}
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty())q2.push(x);
        else q2.push(x);
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q2.empty())swap(q1,q2);
        if(q2.empty())return -1;
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();
        }
        int res=q2.front();
        q2.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if(q2.empty())swap(q1,q2);
        if(q2.empty())return -1;
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();
        }
        int res=q2.front();
        q1.push(q2.front());
        q2.pop();
        return res;
    }
    bool empty() {
        return q1.empty()&&q2.empty();
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