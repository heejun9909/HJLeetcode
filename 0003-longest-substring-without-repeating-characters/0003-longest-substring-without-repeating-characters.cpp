class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use set to detect duplicates
        unordered_set<char> st;
        int res = 0;
        
        // use two pointer technique to implement the sliding window
        int l = 0;


        for(int r=0; r<s.size(); ++r)
        {
            // when encountered a duplicate, keep on eliminating from the left one by one
            // until the duplicate is deleted and now there is a room for the encountered element
            while(st.count(s[r]) != 0)
            {
                st.erase(s[l]);
                ++l;
            }
            st.insert(s[r]);
            
            // calculate the distance of the indices and take the maximum
            res = max(res, r - l + 1);
        }

        return res;
    }
};