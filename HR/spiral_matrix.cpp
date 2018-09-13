class Solution {
public:
    // using 4 pointer
    // Time O(n^2)  Space O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (0 == matrix.size()) return ans;
        int x_s = 0, x_e = matrix[0].size() - 1, y_s = 0, y_e = matrix.size() - 1;
        while (x_s <= x_e && y_s <= y_e) {
            for (int i = x_s; i <= x_e; i++) {
                int num = matrix[y_s][i];
                ans.push_back(num);
                //cout << num << endl;
            }
            y_s++;
            if (y_s > y_e) break;
            for (int j = y_s; j <= y_e; j++) {
                int num = matrix[j][x_e];
                ans.push_back(num);
                //cout << num << endl;
            }
            x_e--;
            if (x_s > x_e) break;
            for (int i = x_e; i >= x_s; i--) {
                int num = matrix[y_e][i];
                ans.push_back(num);
                //cout << num << endl;
            }
            y_e--;
            if (y_s > y_e) break;
            for (int j = y_e; j >= y_s; j--) {
                int num = matrix[j][x_s];
                ans.push_back(num);
                //cout << num << endl;
            }
            x_s++;
        }
        return ans;
    }
};
