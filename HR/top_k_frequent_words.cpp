class Solution {
public:
    class Comp
    {
    public:
        bool operator() (pair<int, string> &a, pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> MP;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            MP[words[i]]++;
        }
        priority_queue <pair<int,string>, vector<pair<int,string>>, Comp> PQ;
        for (auto itr = MP.begin(); itr != MP.end(); itr++) {
            if (PQ.size() < k) PQ.emplace(itr->second, itr->first);
            else {
                pair<int, string> x = make_pair(itr->second, itr->first), y = PQ.top();
                PQ.push(x);
                PQ.pop();
            }
        }
        while (!PQ.empty()) {
            ans.insert(ans.begin(), PQ.top().second);
            PQ.pop();
        }
        return ans;
    }
};
