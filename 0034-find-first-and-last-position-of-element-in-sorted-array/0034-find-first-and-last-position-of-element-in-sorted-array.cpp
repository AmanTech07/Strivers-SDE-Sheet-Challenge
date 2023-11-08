class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int l1=0,  r1= nums.size()-1;
        while(l1<r1){
            int m1= l1+ (r1-l1)/2;
            if(nums[m1]>=target){
                r1=m1;
            }
            else{
                l1=m1+1;
            }
        }

        int l2=0, r2= nums.size()-1;
        while(l2<=r2){
            int m2= l2+ (r2-l2)/2;
            if(nums[m2]>target){
                r2=m2-1;
            }
            else{
                l2=m2+1;
            }
        }

        if(nums[l1]!=target){
            return {-1,-1};
        }
        // if(l1==l2){
        //     return{l1,l2};
        // }
        return {l1, r2};
    }
};