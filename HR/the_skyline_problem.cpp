class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<tuple<int, int, bool>> sweep_line;   // pos, height, start/end
        for (int i = 0; i < buildings.size(); i++) {
            int Li = buildings[i][0], Ri = buildings[i][1], Hi = buildings[i][2];
            sweep_line.insert(make_tuple(Li, -Hi, false));
            sweep_line.insert(make_tuple(Ri, Hi, true));
        }
        map<int, int> mp;  // height, number
        vector<pair<int, int>> rt;  // x, y
        int current_height = 0;
        for (auto itr = sweep_line.begin(); itr != sweep_line.end(); ++itr) {
            int height = get<1>(*itr);
            if (!get<2>(*itr)) {
                height = -height;
                if (height > current_height) {
                    current_height = height;
                    rt.push_back(make_pair(get<0>(*itr), current_height));
                }
                if (mp.find(height) == mp.end()) {
                    mp[height] = 1;
                } else {
                    mp[height]++;
                }
            } else {
                mp[height]--;
                if (!mp[height]) {
                    mp.erase(height);
                    if (current_height == height) {
                        if (mp.empty()) {
                            current_height = 0;
                        } else {
                            auto mpr = mp.end();
                            mpr--;
                            current_height = mpr->first;
                        }
                        rt.push_back(make_pair(get<0>(*itr), current_height));
                    }
                }
            }
        }
        return rt;
    }
};
