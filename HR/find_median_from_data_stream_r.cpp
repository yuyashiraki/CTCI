class MedianFinder {
public:
    // Using priority queue
    // Time O(log(n))  Space O(n)
    priority_queue<int, vector<int>, greater<int>> PQL;
    priority_queue<int> PQR;
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        PQL.push(num);
        PQR.push(PQL.top());
        PQL.pop();
        while (PQR.size() > PQL.size()) {
            PQL.push(PQR.top());
            PQR.pop();
        }
    }

    double findMedian() {
        if (PQL.size() > PQR.size()) {
            return PQL.top();
        } else if (PQL.size() && PQL.size() == PQR.size()) {
            return (double)(PQL.top() + PQR.top()) / 2;
        } else {
            return 0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
