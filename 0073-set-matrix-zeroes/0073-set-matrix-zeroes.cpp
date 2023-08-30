class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        bool row = false, col = false;
        int n = v.size(), m = v[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && v[i][j]==0) row = true;
                if(j==0 && v[i][j]==0) col = true;
                if(v[i][j]==0) {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(v[0][j]==0 || v[i][0]==0) v[i][j] = 0;
            }
        }
        if(col==1) {
            for(int i=0; i<n; i++) v[i][0] = 0;
        } 
        if(row==1) {
            for(int j=0; j<m; j++) v[0][j] = 0; 
        }
    }
};