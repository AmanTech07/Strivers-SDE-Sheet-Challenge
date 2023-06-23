class Solution {
public:
    // int func(int cur, int dif, vector<int>& v, vector<vector<int>>& dp) {
    // int func(int cur, int dif, vector<int>& v, int dp[][1200]) {
    //     if(cur==v.size()) return 0;
    //     if(dp[cur][dif+501]!=-1) return dp[cur][dif+501];
    //     int ans = 1;
    //     if(dif==-501) {
    //         for(int i=cur+1; i<v.size(); i++) {
    //             ans = max(ans, func(i, v[i]-v[cur], v, dp)+1);
    //             ans = max(ans, func(i, dif, v, dp));
    //         }
    //     }
    //     else {
    //         for(int i=cur+1; i<v.size(); i++) {
    //             if(v[i]-v[cur]==dif) {
    //                 ans = max(ans, func(i, dif, v, dp)+1);
    //             }
    //         }
    //     }
    //     return dp[cur][dif+501] = ans;
    // }

    // int func(int i, int dif, vector<int>& v, unordered_map<int, int> dp[]) {
    int func(int i, int dif, vector<int>& v, vector<vector<int>>& dp) {
        if(i==v.size()) return 0;
        // if(mp[i].count(dif)) return mp[i][dif];
        if(dp[i][dif+501]!=-1) return dp[i][dif+501];
        int ans = 0;
        for(int j=i-1; j>=0; j--) {
            if(v[i]-v[j]==dif) ans = max(ans, func(j, dif, v, dp)+1);
        }
        return dp[i][dif+501] = ans;
    }

    int longestArithSeqLength(vector<int>& v) {
        int n = v.size();
        // int dp[n+1][1200];
        // for(int i=0; i<=n; i++) for(int j=0; j<1200; j++) dp[i][j] = -1;
        // return func(0, -501, v, dp);
        if(n<=2) return n;

        // unordered_map<int, int> mp[n+1];
        vector<vector<int>> dp(n+1, vector<int>(2000, -1));
        int ans = 0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int cnt = 1, dif = v[i]-v[j]+501;
                if(dp[j][dif]!=-1) cnt = dp[j][dif];
                dp[i][dif] = 1+cnt;
                ans = max(ans, dp[i][dif]);
            }
        }
        return ans;
    }
};