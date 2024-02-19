class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_set<char> sSet;
        unordered_set<char> tSet;
        unordered_set<char> pSet;

        unordered_multiset<char> smSet;
        unordered_multiset<char> tmSet;

        unordered_set<char>::iterator iter;
        
        if (s.length() != t.length())
        {
            return false;
        }

        for(int i=0; i<s.length(); ++i)
        {
            pSet.insert(s[i]);
            pSet.insert(t[i]);
        }

        for(int i=0; i<s.length(); ++i)
        {
            tSet.insert(t[i]);
            tmSet.insert(t[i]);
        }
        for(int i=0; i<s.length(); ++i)
        {
            sSet.insert(s[i]);
            smSet.insert(s[i]);
        }

        if(sSet.size() != tSet.size())
        {
            return false;
        }

        iter = pSet.begin();
        if(pSet.size() == tSet.size())
        {
            for(int i = 0; i<pSet.size(); ++i)
            {
                if(tmSet.count(*iter) != smSet.count(*iter))
                {
                    return false;
                }
                iter = iter++;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};