class Solution {
public:
    // int func(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {
    //     if(amt==0) return 1;
    //     if(i==-1) return 0;
    //     if(dp[i][amt]!=-1) return dp[i][amt];
    //     int ans = func(i-1, amt, coins, dp);
    //     if(coins[i]<=amt) ans += func(i, amt-coins[i], coins, dp);
    //     return dp[i][amt] = ans;
    // }

    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amt+1, 0));
        // return func(coins.size()-1, amt, coins, dp);
        int n = coins.size();
        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=amt; j++) {
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i-1]) dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amt];
    }
};