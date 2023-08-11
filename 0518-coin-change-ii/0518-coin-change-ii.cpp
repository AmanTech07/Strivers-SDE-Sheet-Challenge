class Solution {
public:
    int func(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if(amt==0) return 1;
        if(i==coins.size()) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int ans = 0;
        for(int j=i; j<coins.size(); j++) {
            if(coins[j]<=amt) ans += func(j, amt-coins[j], coins, dp);
        }
        return dp[i][amt] = ans;
    }

    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amt+1, -1));
        return func(0, amt, coins, dp);
    }
};