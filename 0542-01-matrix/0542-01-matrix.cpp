class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
	    queue<pair<int, int>> q;
	    vector<int> r = {1, -1, 0, 0}, c = {0, 0, 1, -1};
	    vector<vector<int>> vis(n+1, vector<int> (m+1, 0));
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(g[i][j]==0) {
	                vis[i][j] = 1;
	                q.push({i, j});
	            }
	        }
	    }
	    int level = 0;
	    while(!q.empty()) {
	        int sz = q.size();
	        while(sz--) {
	            int i = q.front().first, j = q.front().second;
	            g[i][j] = level;
	            q.pop();
	            for(int k=0; k<4; k++) {
	                int x = i+r[k], y = j+c[k];
	                if(x<0 || y<0 || x>=n || y>=m) continue;
	                if(!vis[x][y]) {
	                    vis[x][y] = 1;
	                    q.push({x, y});
	                }
	            }
	        }
	        level++;
	    }
	    return g;
    }
};