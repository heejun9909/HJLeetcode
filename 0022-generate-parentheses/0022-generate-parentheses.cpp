// This is a backtracking algorithm question using stack DS, but it is much clearer when stack is not used
class Solution {
public:
    vector<string> ans;

    void backtrack(int openB, int closeB, int n, string make)
        {
            if(openB == n && closeB == n)
            {
                ans.push_back(make);
                return;
            }
            
            if(openB < n)
            {
                backtrack(openB + 1, closeB, n, make+'(');
            }

            if(closeB < openB)
            {
                backtrack(openB, closeB + 1, n, make+')');
            }
        }

    vector<string> generateParenthesis(int n) {
        // This is a backtracking algorithm problem using recursion
        // There are 3 keys to this
        // 1. Choice
        // 2. Constraints
        // 3. Goal

        // For this question, we have 3 constraints
        // 1. Only add open bracket if open < n
        // 2. Only add close bracket if close < open
        // 3. Valid iff open == close == n

        backtrack(0, 0, n, "");
        return ans;
    }
};
