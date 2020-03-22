class CQueue {
public:
    stack<int> sk1,sk2;
    CQueue() {}
    void appendTail(int value) {
        if(sk1.empty()&&sk2.empty())sk1.push(value);
        else sk2.push(value);
    }
    int deleteHead() {
        if(sk1.empty()){
            while(!sk2.empty()){
                sk1.push(sk2.top());
                sk2.pop();
            }
        }
        if(sk1.empty())return -1;
        int res=sk1.top();
        sk1.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */