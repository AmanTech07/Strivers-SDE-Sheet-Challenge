class Solution {
public:
    int dfs(int i, vector<int>& vis, vector<vector<int>>& g) {
        vis[i] = 2;
        for(auto &x: g[i]) {
            if(vis[x]==0) {
                if(dfs(x, vis, g)==-1) {
                    vis[i] = -1;
                    return -1;
                }
            }
            else if(vis[x]==2 || vis[x]==-1) {
                vis[i] = -1;
                return -1;
            }
        }
        vis[i]--;
        return vis[i];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n, 0), ans;
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                dfs(i, vis, g);
            }
        }
        for(int i=0; i<n; i++) {
            if(vis[i]==1) ans.push_back(i);
        }
        return ans;
    }
};