#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for(auto num: nums){
            int index = abs(num) - 1;
            if(nums[index] < 0){
                duplicates.push_back(abs(num)) ;
            }
            nums[index] *= -1; 
        }
        return duplicates;
    }
};