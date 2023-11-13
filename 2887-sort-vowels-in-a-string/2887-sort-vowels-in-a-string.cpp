class Solution {
public:
    string sortVowels(string s) {
        string v = "";
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U') {
                v += s[i];
            }
        }
        sort(v.begin(), v.end());
        int j = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U') {
                s[i] = v[j++];
            }
        }
        return s;
    }
};