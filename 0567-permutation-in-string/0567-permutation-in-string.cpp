class Solution {
public:
    bool checkmatch(vector<int>& s1, vector<int>& s2)
    {
        int matches = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(s1[i] == s2[i])
            {
                ++matches;
            }
        }

        if(matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    

    bool checkInclusion(string s1, string s2) {
        // THIS CODE IS WRITTEN BY MYSELF
        // IT IS WORKABLE BUT VERY INEFFICIENT
        
        // int winSize = s1.size();
        // sort(s1.begin(), s1.end());
        // string res = "";
        // int l = 0;
        
        // for(int r = 0; r < s2.size(); ++r)
        // {
        //     res += s2[r];
        //     if(res.size() == winSize)
        //     {
        //         auto temp = res;
        //         sort(temp.begin(), temp.end());
        //         if(temp == s1)
        //         {
        //             return true;
        //         }
        //         else
        //         {
        //             res.erase(0,1);
        //         }
        //     }
        // }
        // return false;

        if(s1.size() > s2.size())
        {
            return false;
        }

        vector<int> s1hash(26);
        vector<int> s2hash(26);

        int winsize = s1.size();

        for(int i=0; i<winsize; ++i)
        {
            ++s1hash[s1[i] - 'a'];
            ++s2hash[s2[i] - 'a'];
        }

        int l = 0;
        int r = winsize - 1;

        while(r < s2.size())
        {
            if(checkmatch(s1hash, s2hash))
            {
                return true;
            }
            else
            {
                --s2hash[s2[l] - 'a'];
                ++l;
                ++r;
                if(r < s2.size())
                {
                    ++s2hash[s2[r] - 'a'];
                }
            }
        }

        return false;
        
    }
};
