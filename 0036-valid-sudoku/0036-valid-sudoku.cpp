class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> sset;
        for(int j=0; j<9; ++j)
        {
            for(int i=0; i<9; ++i)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                string row = "row"+to_string(i)+board[i][j];
                string col = "col"+to_string(j)+board[i][j];
                string box = "box"+to_string(((i/3)*3 + (j/3)))+board[i][j];

                if(sset.find(row) == sset.end() && sset.find(col) == sset.end() && sset.find(box) == sset.end())
                {
                    sset.insert(row);
                    sset.insert(col);
                    sset.insert(box);
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};