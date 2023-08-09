class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        int ind = 0;
        for(int i=1; i<strs.size(); i++) {
            ind = min(common.size(), strs[i].size());
            for(int j=0; j<min(common.size(), strs[i].size()); j++) {
                if(common[j]!=strs[i][j]) {
                    ind = j;
                    break;
                }
            }
            common = common.substr(0, ind);
        }
        return common;
    }
};