class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map <string, vector<string>> mp;
        
        for(auto x: string_list){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x:mp)
            ans.push_back(x.second);
            
        return ans;
    }
};