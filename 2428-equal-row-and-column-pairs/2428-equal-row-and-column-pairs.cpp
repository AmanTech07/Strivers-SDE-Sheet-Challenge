class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n = v.size(), cnt = 0;
        for(int p=0; p<n; p++) {
            for(int k=0; k<n; k++) {
                int i=0, j=0;
                while(i<n && j<n && v[i][k]==v[p][j]) {
                    i++, j++;
                }
                if(i>=n) cnt++;
            }
        }
        return cnt;
    }
};