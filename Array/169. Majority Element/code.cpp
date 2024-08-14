//Approach 1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};

//Approach 2 : Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for(auto num :nums){
            if(count == 0){
                res=num;
            }
            if(num != res){
                count--;
            }else{
                count++;
            }
        }
        return res;
    }