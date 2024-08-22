class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int k=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                k=i;
        }
        return k;
    }
};