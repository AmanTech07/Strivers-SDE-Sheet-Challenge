class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        // int cnt = 1, ele = v[0], ign, n = v.size();
        // for(int i=1; i<n; i++) {
        //     if(v[i]==ele) cnt++;
        //     else cnt--;
        //     if(cnt<=0) {
        //         cnt = 1;
        //         ele = v[i];
        //     }
        // }
        // ign = ele, cnt = 0;
        // int flg = 0, frst=0, scnd = 0;
        // for(int i=0; i<n; i++) {
        //     if(v[i]==ign) continue;
        //     if(!flg) {
        //         ele = v[i], cnt = 1, flg = 1;
        //     }
        //     else {
        //         if(v[i]==ele) cnt++;
        //         else cnt--;
        //     }
        //     if(cnt<=0) {
        //         cnt = 1, ele = v[i];
        //     }
        // }
        // for(int i=0; i<n; i++) {
        //     if(v[i]==ign) frst++;
        //     else if(v[i]==ele) scnd++;
        // }
        vector<int> ans;
        // if(frst>n/3) ans.push_back(ign);
        // if(scnd>n/3) ans.push_back(ele);
        // return ans;
        map<int, int> m;
        set<int> s;
        int n = v.size();
        for(int i=0; i<n; i++) {
            m[v[i]]++;
            if(m[v[i]]>n/3) s.insert(v[i]);
        }
        for(auto &x: s) ans.push_back(x);
        return ans;
    }
};