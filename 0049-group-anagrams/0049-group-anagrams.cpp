// Idea is to create local array for each loop for the anagram and push the local array to the final array after the end of loop
// First send the 0th element of the input to the local array for comparison and check if anything in the input is anagram of the 0th element of the local array
// If anagram is found, use .erase() function to erase the element and shrink the size of the input
// Do the loop until input array size is zero
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>::iterator iter = strs.begin();
        vector<vector<string>> finalGR;

        while(strs.size() != 0)
        {
            iter = strs.begin();
            vector<string> group;
            group.push_back(*iter);
            iter = strs.erase(iter);

            for(;iter != strs.end();)
            {

                if(group[0].length() != (*iter).length())
                {
                    iter++;
                    continue;
                }

                else
                {
                    
                    if (group[0].size() == 0)
                    {
                        group.push_back(*iter);
                        iter = strs.erase(iter);
                    }
                    else
                    {
                        vector<int> alphabet(26);
                        for(int j=0; j<group[0].size(); j++)
                        {
                            alphabet[group[0][j] - 'a']++;
                        }
                        for(int k=0; k<(*iter).size(); k++)
                        {
                            int x = --alphabet[(*iter)[k] - 'a'];
                            
                            if(x < 0)
                            {
                                iter++;
                                break;
                            }
                            else if(k == (*iter).size()-1)
                            {
                                group.push_back(*iter);
                                iter = strs.erase(iter);
                            }
                        }
                    }
                    
                }
            }
            finalGR.push_back(group);
        }

        return finalGR;
        
        
    }
};

//-------------------------------------------------------------------------------------------------------------//
// Better solution from LeetCode
// Idea is to create an unordered map to store representative key for every following anagrams
// for ex) representative key for eat, tea, ate is aet -> sorted
// and store a vector for that particular key to store all the anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;

        // loop through the input strs to store all the representative keys by sorting the words
        // push back all the words that belong to the key
        for(auto x:strs)
        {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        // create a final vector to store the value (vector of strings) for corresponding keys
        vector<vector<string>> ans;
        for(auto y:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
}























