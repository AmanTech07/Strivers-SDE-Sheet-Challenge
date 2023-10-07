class Solution {
    const int M = 1e9+7;
    int func(int i, int k, int prev, int n, int m, vector<vector<vector<int>>> &dp) {
        if(k<0) return 0;
        if(i==n) return k==0;
        if(dp[i][k][prev]!=-1) return dp[i][k][prev];
        int ans = 0;
        for(int j=1; j<=m; j++) {
            if(j>prev) {
                ans = (ans + func(i+1, k-1, j, n, m, dp))%M;
            }
            else ans = (ans + func(i+1, k, prev, n, m, dp))%M;
        }
        return dp[i][k][prev] = ans;
    }
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (m+1, -1)));
        return func(0, k, 0, n, m, dp);
    }
};