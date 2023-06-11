class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<v.size(); i++) {
            int rem = target-v[i];
            if(m.count(rem)) {
                return {m[rem], i};
            }
            m[v[i]] = i;
        }
        return {};
    }
};