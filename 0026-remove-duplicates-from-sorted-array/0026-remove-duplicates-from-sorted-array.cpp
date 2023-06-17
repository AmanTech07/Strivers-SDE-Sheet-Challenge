class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size(), j = 0;
        for(int i=0; i<n; i++) {
            if(m.find(nums[i])==m.end()) {
                m[nums[i]]++;
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};