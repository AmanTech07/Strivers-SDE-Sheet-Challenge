class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if(g[0][0]==1 || g[n-1][n-1]==1) return -1;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;
        set<pair<int, pair<int, int>>> st;
        st.insert({1, {0,0}});
        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1}, y = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!st.empty()) {
            auto ele = *st.begin();
            st.erase(ele);
            int d = ele.first, x_pt = ele.second.first, y_pt = ele.second.second;
            for(int k=0; k<8; k++) {
                int i = x[k] + x_pt, j = y[k] + y_pt;
                if(i<0 || i==n || j<0 || j==n || g[i][j]==1 || (dis[i][j]<=d+1)) continue; 
                dis[i][j] = d+1;
                st.insert({dis[i][j], {i, j}});
                if(i==n-1 && j==n-1) return dis[i][j];
            }
        }
        return dis[n-1][n-1]==1e9?-1:dis[n-1][n-1];
    }
};