class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), cur(m+1, 0);
        // in space optimization change dp[i-1] to prev, and dp[i] to cur
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1]==t[j-1]) cur[j] = prev[j-1] + 1;
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return cur[m];
    }
};