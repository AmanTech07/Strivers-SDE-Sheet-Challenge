class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        map<int, int> m;
        int n = v.size();
        for(int i=0; i<n; i++) {
            m[v[i]] = v[i]+1;
        }
        int cnt = 0, maxi = 0, flg = INT_MIN;
        for(auto &x: m) {
            cout<<x.first<<" "<<x.second<<endl;
            if(flg==INT_MIN || x.first==flg) {
                cnt++;
                flg = x.second;
            }
            else { 
                maxi = max(maxi, cnt);
                cnt = 1;
                flg = x.second;
                cout<<x.first<<" "<<x.second<<" "<<cnt<<endl;
            }
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};