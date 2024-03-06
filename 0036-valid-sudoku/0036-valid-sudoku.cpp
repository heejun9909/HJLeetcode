// Solution from Youtube
// The idea is to check each row, col, and 3x3 box and store unique strings for checking duplicates
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create a set to store strings
        unordered_set<string> sset;
        
        for(int j=0; j<9; ++j)
        {
            for(int i=0; i<9; ++i)
            {
                // ignore if the character is '.'
                if(board[i][j] == '.')
                {
                    continue;
                }

                // create variables to store strings according to their orientation
                string row = "row"+to_string(i)+board[i][j];
                string col = "col"+to_string(j)+board[i][j];

                // ((i/3)*3 + (j/3)) tells the position of the incoming char when the sudoku is divided into 9 pieces
                // 0    1    2
                // 3    4    5
                // 6    7    8
                string box = "box"+to_string(((i/3)*3 + (j/3)))+board[i][j];

                // check if any of the incoming char is already in the set
                if(sset.find(row) == sset.end() && sset.find(col) == sset.end() && sset.find(box) == sset.end())
                {
                    // if not, it is safe to insert the new string
                    sset.insert(row);
                    sset.insert(col);
                    sset.insert(box);
                }
                // if duplicate is detected, return false
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
