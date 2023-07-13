class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dif(n, vector<int> (m, 1e9));
        dif[0][0] = 0;
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {0, 0}});
        vector<int> x = {1, -1, 0, 0}, y = {0, 0, 1, -1};
        while(!st.empty()) {
            auto ele = *st.begin();
            st.erase(ele);
            int prev = ele.first, x_cur = ele.second.first, y_cur = ele.second.second;
            for(int k=0; k<4; k++) {
                int i = x[k] + x_cur, j = y[k] + y_cur;
                if(i<0 || i==n || j<0 || j==m) continue;
                int d = max(prev, abs(g[i][j]-g[x_cur][y_cur]));
                if(dif[i][j]<=d) continue;
                dif[i][j] = d;
                st.insert({dif[i][j], {i, j}});
            }
        }
        return dif[n-1][m-1];
    }
};