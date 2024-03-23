// Idea is to evaluate two uppermost values in the stack whenever an operator (+,-,/,*) is encountered
// evaluate according to the operator and push the result back to the stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> tok;
        for(auto n:tokens)
        {
            if(n == "+")
            {
                int num = stoi(tok.top());
                tok.pop();
                int num2 = stoi(tok.top());
                tok.pop();
                tok.push(to_string(num + num2));
            }
            else if(n == "-")
            {
                int num = stoi(tok.top());
                tok.pop();
                int num2 = stoi(tok.top());
                tok.pop();
                tok.push(to_string(num2 - num));
            }
            else if(n == "*")
            {
                int num = stoi(tok.top());
                tok.pop();
                int num2 = stoi(tok.top());
                tok.pop();
                tok.push(to_string(num * num2));
            }
            else if(n == "/")
            {
                int num = stoi(tok.top());
                tok.pop();
                int num2 = stoi(tok.top());
                tok.pop();
                tok.push(to_string(int(num2/num)));
            }
            else
            {
                tok.push(n);
            }
        }
        return stoi(tok.top());

    }
};
