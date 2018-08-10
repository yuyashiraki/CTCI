class Solution {
public:
    // Using HashTable
    // Time O(n^2)  Space O(n^2)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ST;
        vector<vector<int>> ans;
        if (!nums.size()) return ans;
        unordered_map<int, vector<pair<int, int>>> MP;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                MP[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        for (auto itr = MP.begin(); itr != MP.end(); ++itr) {
            //cout << itr->first << endl;
            if (MP.count(target - itr->first)) {
                //cout << "DEBUG" << endl;
                vector<pair<int, int>> V1 = MP[target - itr->first];
                vector<pair<int, int>> V2 = itr->second;
                for (int v1x = 0; v1x < V1.size(); v1x++) {
                    for (int v2x = 0; v2x < V2.size(); v2x++) {
                        //cout << V1[v1x].first << " " << V1[v1x].second << " " << V2[v2x].first << " " << V2[v2x].second << endl;
                        if (V1[v1x].first != V2[v2x].first && V1[v1x].second != V2[v2x].second && V1[v1x].first != V2[v2x].second && V1[v1x].second != V2[v2x].first) {
                            vector<int> elm{nums[V1[v1x].first], nums[V1[v1x].second], nums[V2[v2x].first], nums[V2[v2x].second]};
                            sort(elm.begin(), elm.end());
                            ST.insert(elm);
                        }
                    }
                }
            } else {
                continue;
            }
        }
        for (auto itr = ST.begin(); itr != ST.end(); ++itr) {
            ans.push_back(*itr);
        }
        return ans;
    }
};
