class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        set<int> r, c;
        int m = v.size(), n = v[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j]==0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto &x: r) {
            for(int j=0; j<n; j++) {
                v[x][j] = 0;
            }
        }
        for(auto &y: c) {
            for(int i=0; i<m; i++) {
                v[i][y] = 0;
            }
        }
    }
    // -------------TC: O(n^2 log (n))------------
    // -------------SC: O(2n) {this is extra time complexity}-----------
};