class Solution {
    int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(s1[i]==s2[j]) {
            ans = func(i+1, j+1, s1, s2, dp)+1;
        }
        else {
            ans = func(i+1, j, s1, s2, dp);
            ans = max(ans, func(i, j+1, s1, s2, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return func(0, 0, s, str, dp);
    }
};