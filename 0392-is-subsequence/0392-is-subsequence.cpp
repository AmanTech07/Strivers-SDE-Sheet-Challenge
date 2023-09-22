class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, n=s.size(), m=t.size();
        for(int j=0; j<m; j++){
            if(i==n) return true;
            if(s[i]==t[j]) i++;
        }
        if(i==n) return true;
        return false;
    }
};