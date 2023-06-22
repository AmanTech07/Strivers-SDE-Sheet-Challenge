class Solution {
public:
    int func(int cur, bool canBuy, vector<int>& v, int fee, vector<vector<int>>& dp) {
        if(cur==v.size()) return 0;
        if(dp[cur][canBuy]!=-1) return dp[cur][canBuy];
        int ans = func(cur+1, canBuy, v, fee, dp);
        if(canBuy) {
            ans = max(ans, func(cur+1, 0, v, fee, dp)-v[cur]);
        }
        else {
            ans = max(ans, func(cur+1, 1, v, fee, dp)+(v[cur]-fee));
        }
        return dp[cur][canBuy] = ans;
    }

    int maxProfit(vector<int>& v, int fee) {
        vector<vector<int>> dp(v.size()+1, vector<int> (2, -1));
        return func(0, 1, v, fee, dp);
    }
};