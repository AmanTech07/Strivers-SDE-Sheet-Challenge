class Solution {
public:
    vector<int> r = {1, -1, 0, 0}, c = {0, 0, 1, -1};
    void dfs(int i, int j, int m, int n, int old, int nw, vector<vector<int>>& image) {
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=old) return;
        image[i][j] = nw;
        for(int k=0; k<4; k++) {
            dfs(i+r[k], j+c[k], m, n, old, nw, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), start = image[sr][sc];
        if(start!=color) dfs(sr, sc, m, n, start, color, image);
        return image;
    }
};

// -------------------TC: O(number of pixels in the image)-----------------------
// -------------------SC: O(the size of implicit call stack)-----------------------