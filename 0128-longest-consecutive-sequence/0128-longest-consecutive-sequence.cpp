// Solution from YouTube
// https://www.youtube.com/watch?v=P6RZZMu_maU
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
            // for any number, if (number-1) exist, that means that number
            // is NOT the start of the sequence, so we need to find the
            // start of the sequence
            if(st.find(n-1) == st.end())
            {
                int length = 0;

                // after the start of the sequence, loop through and search for the
                // element that is 1 bigger and if there is, increase the sequence length
                // until no more is found
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

                // compare with the longest variable
                if(length > longest)
                {
                    longest = length;
                }
            }
        }
        return longest;
    }
};
