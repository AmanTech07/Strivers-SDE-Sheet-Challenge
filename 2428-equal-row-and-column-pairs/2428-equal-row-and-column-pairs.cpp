class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n = v.size(), cnt = 0;
        map<vector<int>,int> m;
        for(int i=0; i<n; i++) {
            m[v[i]] += 1;
        }
        for(int i=0; i<n; i++) {
            vector<int> vec(n);
            for(int j=0; j<n; j++) {
                vec[j] = v[j][i];
            }
            cnt += m[vec];
        }
        return cnt;
    }
};