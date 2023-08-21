class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 0, j = 1, prev = 2, n = s.size();
        while(j<n) {
            if(s[i]!=s[j]) {
                i = 0, j = prev, prev++;
                continue;
            }
            i++, j++;
            if(j==n) {
                if(i%(prev-1)==0) return true;
            } 
        }
        return false;
    }
};