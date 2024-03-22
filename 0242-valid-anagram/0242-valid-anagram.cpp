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

//----------------------------------------------------------------------------------------------------//
// Better version from Youtube
// The idea is to loop through the first string to increase the number of alphabet encounters
// Then loop through the second string to decrease the number when the same alphabets are encountered
// When all the encounter numbers are exactly zero, they are anagram
// ex) rat & car
// r -> 1 - 1 = 0
// a -> 1 - 1 = 0
// t -> 1
// So, t is 1, which makes it invalid

class Solution {
public:
    bool isAnagram(string s, string t) {
        // The original size cannot be different
        if(s.size() != t.size())
        {
            return false;
        }

        // Make an array that can hold the number of alphabets from a ~ z
        vector<int> alphabet_arr(26);

        for(int i = 0; i < s.size(); i++)
        {
            // if s[i] is 'c', c - a is 2, so the area of index 2 in alphabet_arr will be increased by 1
            alphabet_arr[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++)
        {
            // decrease the alphabet area by 1 when encountering the same alphabet in the second string
            int x = --alphabet_arr[t[i] - 'a'];

            // x is smaller than 0 means it is not valid, because the length is conditioned to be the same
            // so x cannot be negative if it is valid
            if(x < 0)
            {
                return false;
            }
        }
        return true;
    }
}
