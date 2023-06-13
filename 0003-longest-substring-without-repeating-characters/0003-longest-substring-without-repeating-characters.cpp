class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0, n = s.size(), i=0, j=0;
        map<char, int> m;
        while(j<n) {
            if(m.find(s[j])!=m.end()) {
                // cout<<j<<" "<<i<<endl;
                cnt = max(cnt, (j-i));
                i = max(i, m[s[j]]+1);
            }
            m[s[j]] = j;
            j++;
        }
        cnt = max(cnt, j-i);
        return cnt;
    }
};