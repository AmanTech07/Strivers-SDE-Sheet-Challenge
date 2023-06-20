class Solution {
public:
    void func(int cur, string& s, vector<string>& vs, string& str, vector<vector<string>>& ans) {
        if(cur>=str.size()) {
            ans.push_back(vs);
            return;
        }

        for(int i=cur; i<str.size(); i++) {
            s.push_back(str[i]);
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            if(s==tmp) {
                vs.push_back(s);
                tmp = "";
                func(i+1, tmp, vs, str, ans);
                vs.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string str) {
        vector<vector<string>> ans;
        vector<string> vs;
        string s;
        func(0, s, vs, str, ans);
        return ans;
    }
};