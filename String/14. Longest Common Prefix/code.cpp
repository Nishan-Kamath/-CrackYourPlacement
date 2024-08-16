class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string st1 = strs[0];
        string st2 = strs[strs.size()-1];
        int index = 0;
        while(index<st1.length()){
            if(st1[index] == st2[index])
                index++;
            else
                break;
        }
        if(index == 0)
            return "";
        else
            return st1.substr(0,index);
    }
};