class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        v[0].push_back(1);
        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; j++) {
                int ele = 0;
                if(j<i) ele += v[i-1][j];
                if(j>0) ele += v[i-1][j-1];
                v[i].push_back(ele);
            }
        }
        return v;

        // ----------------------TC: O(n^2)------------------
        // ----------------------SC: O(n^2)------------------
    }
};