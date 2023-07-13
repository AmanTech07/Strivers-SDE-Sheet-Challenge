class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dif(n, vector<int> (m, 1e9));
        dif[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int x[] = {1, -1, 0, 0}, y[] = {0, 0, 1, -1};
        while(!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            int prev = ele.first, x_cur = ele.second.first, y_cur = ele.second.second;
            if(x_cur==n-1 && y_cur==m-1) return dif[n-1][m-1];
            for(int k=0; k<4; k++) {
                int i = x[k] + x_cur, j = y[k] + y_cur;
                if(i<0 || i==n || j<0 || j==m) continue;
                int d = max(prev, abs(g[i][j]-g[x_cur][y_cur]));
                if(dif[i][j]<=d) continue;
                dif[i][j] = d;
                pq.push({dif[i][j], {i, j}});
            }
        }
        return 0;
    }
};