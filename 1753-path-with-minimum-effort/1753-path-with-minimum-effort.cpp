class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& vec) {
        int n = vec.size(), m = vec[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 1e9));
        st.insert({0, {0, 0}});
        vis[0][0] = 0;
        int x[4] = {0, 0, -1, 1}, y[4] = {-1, 1, 0, 0};
        while(!st.empty()) {
            auto it = *st.begin();
            st.erase(it);
            int effort = it.first, u = it.second.first, v = it.second.second;
            for(int i=0; i<4; i++) {
                int xx = u+x[i], yy = v+y[i];
                if(xx>=0 && xx<n && yy>=0 && yy<m) {
                    int prev = vec[u][v], nxt = vec[xx][yy];
                    if(vis[xx][yy]>max(effort,abs(nxt-prev))) {
                        vis[xx][yy] = max(abs(nxt-prev),effort);
                        st.insert({vis[xx][yy], {xx, yy}});
                    }
                }
                
            }
        }
        return vis[n-1][m-1];
    }
};