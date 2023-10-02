class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& s) {
        if(bw.size()!=ew.size() || s.size()==0 || bw==ew) return 0;
        unordered_map<string, int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]] = 1;
        }
        queue<string> q;
        q.push(bw);
        int n = bw.size(), level = 0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                string str = q.front();
                q.pop();
                if(str==ew) return level;
                for(int i=0; i<n; i++) {
                    char ch = str[i];
                    for(char c='a'; c<='z'; c++) {
                        str[i] = c;
                        if(mp[str]==1) {
                            q.push(str);
                            mp[str] = 2;
                        }
                    }
                    str[i] = ch;
                }
            }
        }
        return 0;
    }
};