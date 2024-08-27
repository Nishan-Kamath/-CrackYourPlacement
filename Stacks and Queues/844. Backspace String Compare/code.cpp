class Solution {
public:
    string processString(const string& s){
        string result;
        for(char ch : s){
            if(ch == '#'){
                if(!result.empty())
                    result.pop_back();
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
    bool backspaceCompare(string s, string t) {
        string finalS = processString(s);
        string finalT = processString(t);

        return finalS == finalT;
    }
};