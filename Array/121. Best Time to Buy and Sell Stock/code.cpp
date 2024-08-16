#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxRight = 0;
        int maxProfit = 0;
        for(int i=prices.size()-1;i>=0;i--){
            maxRight = max(maxRight, prices[i]);
            maxProfit = max(maxProfit, maxRight - prices[i]);
        }
        return maxProfit;
    }
};