class Solution {
public:
    vector<int> r={1,-1,0,0}, c={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j]==2) q.push({i, j});
            }
        }
        int time=-1;
        while(!q.empty()) {
            int sz = q.size();
            time++;
            while(sz--) {
                auto ind = q.front();
                q.pop();
                int x = ind.first, y = ind.second;
                for(int i=0; i<4; i++) {
                    if(x+r[i]<0 || x+r[i]>=m || y+c[i]<0 || y+c[i]>=n || g[x+r[i]][y+c[i]]!=1) continue;
                    q.push({x+r[i], y+c[i]});
                    g[x+r[i]][y+c[i]] = 2;
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(g[i][j]==1) return -1;
            }
        }
        return time==-1?0:time;
    }
};