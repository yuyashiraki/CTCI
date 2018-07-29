class Solution {
public:
    // Using topological sort
    // Time O(V+E)  Space O(VE)
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> outdegrees(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> pr = prerequisites[i];
            int course = pr.first, prerq = pr.second;
            indegree[course]++;
            outdegrees[prerq].push_back(course);
        }
        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (0 == indegree[i]) Q.push(i);
        }
        while (!Q.empty()) {
            int C = Q.front(); Q.pop();
            for (int i = 0; i < outdegrees[C].size(); i++) {
                if (--indegree[outdegrees[C][i]] == 0) Q.push(outdegrees[C][i]);
            }
        }
        bool ans = true;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i]) ans = false;
        }
        return ans;
    }
};
