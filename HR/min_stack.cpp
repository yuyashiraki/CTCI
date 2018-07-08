class MinStack {
public:
    /** initialize your data structure here. */
    int minimum = INT_MAX;
    stack<int> min_stack;
    MinStack() {
    }

    void push(int x) {
        if (minimum >= x) {
            min_stack.push(minimum);
            minimum = x;
        }
        min_stack.push(x);
    }

    void pop() {
        if (min_stack.empty()) {
            return;
        }
        int x = top();
        min_stack.pop();
        if (!min_stack.empty() && x == minimum) {
            minimum = min_stack.top();
            min_stack.pop();
        }
    }

    int top() {
        if (min_stack.empty()) {
            return -1;
        }
        return min_stack.top();
    }

    int getMin() {
        return minimum;
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
