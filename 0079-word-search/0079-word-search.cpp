class Solution {
    bool func(int i, int j, int k, int m, int n, vector<vector<char>> &v, string &word, vector<vector<int>> &vis) {
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==m || j==n || vis[i][j]==1 || v[i][j]!=word[k]) return false;
        vis[i][j] = 1;
        bool ans = func(i+1, j, k+1, m, n, v, word, vis);
        ans |= func(i, j+1, k+1, m, n, v, word, vis);
        ans |= func(i-1, j, k+1, m, n, v, word, vis);
        ans |= func(i, j-1, k+1, m, n, v, word, vis);
        vis[i][j] = 0;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& v, string word) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        bool ans = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j]==word[0]) {
                    if(func(i, j, 0, m, n, v, word, vis)) return true;
                }
            }
        }
        return false;
    }
};