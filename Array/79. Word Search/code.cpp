class Solution {
public:

    bool search(int index, int i, int j, vector<vector<char>>& board, string word){
        if(index == word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '*';
        bool ans = false;
    

        ans = search(index+1, i+1, j, board, word) ||
              search(index+1, i, j+1, board, word) ||
              search(index+1, i-1, j, board, word) ||
              search(index+1, i, j-1 ,board, word);

        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board[0].size();
        int n = board.size();
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0] == board[i][j]){
                    if(search(0, i, j, board, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};