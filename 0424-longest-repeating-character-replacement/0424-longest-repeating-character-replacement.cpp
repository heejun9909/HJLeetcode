// The idea is to keep track of the number of the most occuring alphabet within the current window
// Since we have k chances to replace non-major alphabets, it means that it is okay to span the right pointer
// until (current_window_size - number_of_most_occuring_alphabet) <= k 
// because we would want to keep the majority alphabet and change those minority ones
// so, if we subtract the most occuring number from the window size, we get the number that we should replace
// in order to make the current window valid 
class Solution {
public:

    int maxi(vector<int>& arr)
    {
        int res = 0;
        for(auto n:arr)
        {
            res = max(res, n);
        }
        
        return res;
    }

    int characterReplacement(string s, int k) {

        
        int res = 0;
        int l = 0;
        
        // make an array to store the alphabet occurences
        vector<int> arr(26);

        for(int r = 0; r < s.size(); ++r)
        {
            // encounter an alphabet and increment the corresponding index by 1.
            ++arr[s[r] - 'A'];

            // if the number of alphabets we need to replace exceeds k, move the left pointer forward
            // to decrease the window size and decrease the alphabet number that left pointer was pointing
            while((r - l + 1) - maxi(arr) > k)
            {
                --arr[s[l] - 'A'];
                ++l;
            }

            res = max(res, r - l + 1);
        }

        return res;


    }
};