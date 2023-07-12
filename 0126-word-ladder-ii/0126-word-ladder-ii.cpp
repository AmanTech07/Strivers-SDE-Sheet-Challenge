class Solution {
    string start;
    int sw_sz;
    unordered_map<string, int> m;
    vector<vector<string>> ans;
private:
    void dfs(string s, vector<string>& v) {
        if(s==start) {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        int step = m[s];
        for(int i=0; i<sw_sz; i++) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                char org = s[i];
                s[i] = ch;
                if(m.count(s) && m[s]<step) {
                    v.push_back(s);
                    dfs(s, v);
                    v.pop_back();
                }
                s[i] = org;
            }
        }
    }
public:
    vector<vector<string>> findLadders(string sw, string ew, vector<string>& wl) {
        start = sw;
        unordered_set<string> st(wl.begin(), wl.end());
        m[sw] = 0;
        queue<string> q;
        q.push(sw);
        st.erase(sw);
        int level = 0, flg = 0;
        sw_sz = sw.size();
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                string s = q.front();
                q.pop();
                for(int i=0; i<sw_sz; i++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        char org = s[i];
                        s[i] = ch;
                        if(st.count(s)) {
                            q.push(s);
                            m[s] = level;
                            st.erase(s); 
                            if(s==ew) flg = 1;
                        }
                        s[i] = org;
                    }
                }
            }
            if(flg) break;
        }
        if(m.find(ew)!=m.end()) {
            vector<string> v;
            v.push_back(ew);
            dfs(ew, v);
        }
        return ans;    
    }
};