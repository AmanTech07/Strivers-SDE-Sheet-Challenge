class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN, n = v.size();
        for(int i=0; i<n; i++) {
            if(ele1==v[i]) cnt1++;
            else if(ele2==v[i]) cnt2++;
            else if(cnt1==0) {
                ele1 = v[i];
                cnt1 = 1;
            }
            else if(cnt2==0) {
                ele2 = v[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(v[i]==ele1) cnt1++;
            else if(v[i]==ele2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(ele1);
        if(cnt2>n/3) ans.push_back(ele2);
        return ans;
        
    }
};