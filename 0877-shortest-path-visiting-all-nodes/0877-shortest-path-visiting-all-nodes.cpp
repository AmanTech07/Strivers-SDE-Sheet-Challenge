class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int finalState = ((1<<n)-1);
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n+1, vector<int>(finalState+1, 0));
        for(int i=0; i<n; i++) {
            q.push({i, 1<<i});
            vis[i][(1<<i)] = 1;
        }
        int ans = 0;
        while(!q.empty()) {
            ans++;
            int sz = q.size();
            while(sz--) {
                int node = q.front().first, state = q.front().second;
                q.pop();
                for(auto &neighbour: g[node]) {
                    int newState = state | (1<<neighbour);
                    if(vis[neighbour][newState]==1) continue;
                    vis[neighbour][newState] = 1;
                    if(newState==finalState) return ans;
                    q.push({neighbour, newState});
                }
            }
        }
        return 0;
    }
};