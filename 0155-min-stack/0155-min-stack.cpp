// Idea is to make an extra stack for maintaining the min values at each stage
// whenever a value is pushed, check whether that new value is smaller than the min.top() value
// If new value is smaller, update the min.top() value by pushing the new value to the min stack
// and if the new value is greater or same as the min.top() value, we push the same min.top() value to the min stack ( min.push(min.top()) )
class MinStack {
public:
    stack<int> min;
    vector<int> arr;
    MinStack() {
    }
    
    void push(int val) {
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
        vector<int>::iterator iter = this->arr.end();
        iter = --iter;
        iter = this->arr.erase(iter);
    }
    
    int top() {
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
