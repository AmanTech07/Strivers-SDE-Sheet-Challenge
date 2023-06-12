class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        int n = v.size();
        set<vector<int>> ans;
        sort(v.begin(), v.end());
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                long long int k = (target-v[i]-v[j]*1LL)%M;
                int l=j+1, h=n-1;
                while(l<h) {
                    long long int sum = (v[l]+v[h]*1LL)%M;
                    if(k<sum) {
                        h--;
                    }
                    else if(k==sum) {
                        vector<int> tmp = {v[i], v[j], v[l], v[h]};
                        ans.insert(tmp);
                        l++, h--;
                    }
                    else {
                        l++;
                    }
                }
            }
        }
        vector<vector<int>> ans1;
        for(auto &x: ans) {
            ans1.push_back(x);
        }
        return ans1;
    }
};