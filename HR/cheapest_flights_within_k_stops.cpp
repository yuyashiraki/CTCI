class Solution {
public:
    // Dijkstra
    // Time O(Elog(E))  Space O(E)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int, int>>> MP;  // next,cost
        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0], to = flights[i][1], cost = flights[i][2];
            MP[from].push_back(make_pair(to,cost));
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> PQ;  // cost,pos,steps
        PQ.emplace(0,src,-1);
        while (!PQ.empty()) {
            tuple<int,int,int> cur = PQ.top();
            int cost = get<0>(cur), pos = get<1>(cur), steps = get<2>(cur);
            //cout << "POP:" << cost << " " << pos << " " << steps << endl;
            if (pos == dst) return cost;
            PQ.pop();
            if (steps == K) continue;
            vector<pair<int, int>> adj = MP[pos];
            for (int i = 0; i < adj.size(); i++) {
                int nextcost = adj[i].second, nextpos = adj[i].first;
                //cout << "ADD:" << cost + nextcost << " " << nextpos << " " << steps + 1 << endl;
                PQ.emplace(cost + nextcost,nextpos,steps+1);
            }
        }
        return -1;
    }
};
