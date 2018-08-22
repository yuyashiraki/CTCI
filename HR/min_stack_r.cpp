class MinStack {
public:
    // using pair
    // Time O(1) per query  Space O(n)
    stack<pair<int,int>> STK;
    MinStack() {
    }

    void push(int x) {
        if (STK.empty() || STK.top().second > x) {
            STK.emplace(x,x);
        } else {
            STK.emplace(x,STK.top().second);
        }
    }

    void pop() {
        STK.pop();
    }

    int top() {
        return STK.top().first;
    }

    int getMin() {
        return STK.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
