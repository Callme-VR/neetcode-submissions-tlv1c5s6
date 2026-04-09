class MinStack {
public:
    std :: stack<int> mainstk;
    std :: stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int val) {
        mainstk.push(val);
        if(minstk.empty() || val <= minstk.top()){
            minstk.push(val);
        }
        else{
        minstk.push(minstk.top());        }
    }
    
    void pop() {
        mainstk.pop();
        minstk.pop();
    }
    
    int top() {
        return mainstk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
