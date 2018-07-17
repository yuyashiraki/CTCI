class Solution {
public:
    // Using priority queue
    // Time O(answer)  Space O(alphabets)
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        priority_queue<int> pq;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            pq.push(itr->second);
        }
        int cnt = -1, remaining = n + 1;
        while (!pq.empty()) {
            cnt++;
            int x = n + 1;
            remaining = 0;
            queue<int> qq;
            while (!pq.empty() && x--) {
                remaining++;
                int num = pq.top();
                pq.pop();
                if (--num) {
                    qq.push(num);
                }
            }
            while (!qq.empty()) {
                int num = qq.front();
                qq.pop();
                pq.push(num);
            }
        }
        return (n + 1) * cnt + remaining;
    }
};
