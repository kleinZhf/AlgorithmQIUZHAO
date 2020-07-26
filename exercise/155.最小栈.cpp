/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> _data;
    stack<int> _minData;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _data.push(x);
        if (_minData.empty() || x <= _minData.top()) {
            _minData.push(x);
        }
    }
    
    void pop() {
        int x = _data.top();
        _data.pop();
        if (x == _minData.top()) {
            _minData.pop();
        }
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _minData.top();
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
// @lc code=end

