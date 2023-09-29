class Solution {
    int func(int i, vector<int> &v, vector<int> &dp) {
        if(i>=v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = func(i+1, v, dp);
        ans = max(ans, func(i+2, v, dp)+v[i]);
        return dp[i] = ans;
    }
public:
    int rob(vector<int>& v) {
        vector<int> dp(v.size()+1, -1);
        return func(0, v, dp);
    }
};