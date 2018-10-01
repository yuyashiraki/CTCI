class Solution {
public:
    map<string, priority_queue<string>> flights;
    vector<string> path;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            flights[tickets[i].first].push(tickets[i].second);
        }
        dfs("JFK");
        return path;
    }
    void dfs(string departure) {
        priority_queue<string> &arrivals = flights[departure];
        while (!arrivals.empty()) {
            dfs();
        }
    }
};
