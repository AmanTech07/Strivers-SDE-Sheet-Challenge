class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // --------------------TC: O(n*log(n))-----------------
        // --------------------SC: O(j)------------------------

        // map<int, int> m;
        // int n = nums.size(), j = 0;
        // for(int i=0; i<n; i++) {
        //     if(m.find(nums[i])==m.end()) {
        //         m[nums[i]]++;
        //         nums[j++] = nums[i];
        //     }
        // }
        // return j;

        // -------Since vector is sorted so we can do this is in O(n) TC and O(1) SC-------
        // -------------------TC: O(n)-----------------
        // -------------------SC: O(1)-----------------
        int flg = nums[0], j=1, n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i]!=flg) {
                nums[j++] = nums[i];
                flg = nums[i];
            }
        }
        return j;
    }
};