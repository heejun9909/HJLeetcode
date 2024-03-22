class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto n:s)
        {
            if(n != ')' && n != '}' && n != ']')
            {
                stk.push(n);
            }
            else if(n == ')')
            {
                if (stk.empty())
                {
                    return false;
                }
                if(stk.top() != '(')
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
            else if(n == '}')
            {
                if (stk.empty())
                {
                    return false;
                }
                if(stk.top() != '{')
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
            else if(n == ']')
            {
                if (stk.empty())
                {
                    return false;
                }
                if(stk.top() != '[')
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        if(stk.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};