class Solution {
public:

    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> v(n+1, vector<int> (m+1, 0));

        for(int j=1; j<=m; j++) v[0][j] = v[0][j-1]+t[j-1];
        for(int i=1; i<=n; i++){
            v[i][0] = v[i-1][0]+s[i-1];
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]) {
                    v[i][j] = v[i-1][j-1];
                }
                else{
                    v[i][j] = min( (v[i-1][j]+s[i-1]) , (v[i][j-1]+t[j-1]) );
                }
            }
        }
        return v[n][m];
    }
};