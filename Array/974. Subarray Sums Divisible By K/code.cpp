#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int modulusCount[k];

        memset(modulusCount, 0 ,sizeof(modulusCount));
        int currentMod = 0;
        int subarrayCount = 0;
        modulusCount[0] = 1;

        for(int i=0;i<nums.size();i++){
            currentMod = ((currentMod + nums[i] % k) + k) %k;
            subarrayCount += modulusCount[currentMod];
            modulusCount[currentMod]++;
        }
        return subarrayCount;
    }
};