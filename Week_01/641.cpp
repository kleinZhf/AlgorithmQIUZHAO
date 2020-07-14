/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : _q(vector<int>(k)), _size(k), _head(0), _ct(0) {

    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (_ct < _size) {
            _head = (_head + _size - 1) % _size;
            _q[_head] = value;
            ++_ct;
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (_ct < _size) {
            _q[(_head + _ct++) % _size] = value;
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (_ct != 0) {
            _head = (_head + 1) % _size;
            --_ct;
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (_ct != 0) {
            --_ct;
            return true;
        }
        else {
            return false;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (_ct) {
            return _q[_head];
        }
        else {
            return -1;
        }
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (_ct) {
            return _q[(_head + _ct - 1) % _size];
        }
        else {
            return -1;
        }
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _ct == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _ct == _size;
    }
private:
    vector<int> _q;
    int _size;
    int _head;
    int _ct;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

