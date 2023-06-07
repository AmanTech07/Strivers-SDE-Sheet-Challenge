class Solution {
public:
    void sortColors(vector<int>& v) {
        // ---------------Better Approach--------------
        // int cnt0=0, cnt1=0, cnt2=0, n = v.size();
        // for(int i=0; i<n; i++) {
        //     if(v[i]==0) cnt0++;
        //     else if(v[i]==1) cnt1++;
        //     else cnt2++;
        // }
        // for(int i=0; i<n; i++) {
        //     if(cnt0>0) {
        //         v[i]=0, cnt0--;
        //     }
        //     else if(cnt1>0) {
        //         v[i]=1, cnt1--;
        //     }
        //     else v[i]=2;
        // }
        // ------------------TC: O(n)--------------------
        // ------------------SC: O(1)--------------------


        // ------------------Optimal Approach---------------
        // This problem is variation of the popular Dutch National flag algorithm.
        // --------------------------------------------------
        int l = 0, mid = 0, h = v.size()-1, n = v.size();
        while(mid<=h) {
            if(v[mid]==0) {
                swap(v[l], v[mid]);
                l++, mid++;
            }
            else if(v[mid]==1) mid++;
            else {
                swap(v[mid], v[h]);
                h--;
            }
        }
        // --------------------TC: O(n)-----------------------
        // --------------------SC: O(1)-----------------------

    }
};