class Solution {
public:
    // DFS
    // Time O(n)  Space O(n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        //cout << sr << " " << sc << endl;
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        if (sr > 0 && image[sr - 1][sc] == oldColor) floodFill(image, sr - 1, sc, newColor);
        if (sc > 0 && image[sr][sc - 1] == oldColor) floodFill(image, sr, sc - 1, newColor);
        if (sr + 1 < image.size() && image[sr + 1][sc] == oldColor) floodFill(image, sr + 1, sc, newColor);
        if (sc + 1 < image[0].size() && image[sr][sc + 1] == oldColor) floodFill(image, sr, sc + 1, newColor);
        return image;
    }
};
