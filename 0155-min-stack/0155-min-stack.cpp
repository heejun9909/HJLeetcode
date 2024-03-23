class MinStack {
public:
    stack<int> min;
    vector<int> arr;
    MinStack() {
        cout << "start" << endl;
    }
    
    void push(int val) {
        cout << "push" << endl;
        if (arr.size() == 0)
        {
            arr.push_back(val);
            min.push(val);
        }
        else
        {
            arr.push_back(val);
            if(min.top() <= val)
            {
                min.push(min.top());
            }
            else
            {
                min.push(val);
            }
        }
        
    }
    
    void pop() {
        min.pop();
        cout << "pop" << endl;
        vector<int>::iterator iter = this->arr.end();
        iter = --iter;
        iter = this->arr.erase(iter);
    }
    
    int top() {
        cout << "top" << endl;
        vector<int>::iterator iter = this->arr.end();
        iter = --iter;
        int top = *iter;
        return top;
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */