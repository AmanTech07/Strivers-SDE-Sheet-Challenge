class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size(), prev = v[0], j = 1;
        for(int i=1; i<n; i++) {
            if(v[i]!=prev) {
                v[j++] = v[i];
                prev = v[i];
            }
        }
        return j;
    }
};