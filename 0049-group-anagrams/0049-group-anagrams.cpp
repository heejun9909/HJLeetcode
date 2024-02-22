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