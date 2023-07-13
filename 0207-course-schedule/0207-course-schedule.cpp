class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prq) {
        vector<int> g[n], indeg(n, 0);
        for(int i=0; i<prq.size(); i++) {
            g[prq[i][1]].push_back(prq[i][0]);
            indeg[prq[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &x: g[node]) {
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        for(int i=0; i<n; i++) {
            if(indeg[i]!=0) return false;
        }
        return true;
    }
};