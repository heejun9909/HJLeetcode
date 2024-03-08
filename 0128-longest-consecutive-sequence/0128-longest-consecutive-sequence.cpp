class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // make a set to store the nums vector
        // exclude the repetitions
        unordered_set<int> st;

        for(auto n:nums)
        {
            st.insert(n);
        }

        int longest = 0;
        for(auto n:st)
        {
            if(st.find(n-1) == st.end())
            {
                int length = 0;
                while(true)
                {
                    if(st.find(n++) != st.end())
                    {
                        length++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if(length > longest)
                {
                    longest = length;
                }
            }
        }
        return longest;
    }
};