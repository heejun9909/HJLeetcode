class Solution {
public:

    string encode(vector<string>& strs) {
        // make a string so that it can indicate the number of chars in one string
        // followed by a delimeter ex) 4#neet4#code4#love3#you
        // so after the first integer and the delimeter, even if there are integers and
        // same delimeters right after that, we will read the character according to the
        // number that was first encountered, so no problem

        string pass = "";
        for(auto n:strs)
        {
            string len = to_string(n.length());
            
            pass += len + "#" + n;
        }

        return pass;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if (s.length() < 1)
        {
            return ans;
        }
        
        string::iterator iter = s.begin();

        for(;iter != s.end();)
        {
            // In case the length of one string has two digits ex) 10, 20, 30
            // We need to iterate until we meet '#' and combine that number to be our index
            string idxstr = "";
            while(iter != s.end() && *iter != '#')
            {
                idxstr += *iter++;
            }
            int idx = stoi(idxstr);

            iter = ++iter;

            string str = "";
            for (int i=0; i<idx; ++i)
            {
                str += *iter++;
            }

            ans.push_back(str);
        }
        return ans;
    }
};
