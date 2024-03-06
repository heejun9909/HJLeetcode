// The idea is to calculate the prefixes and suffixes (left and right here)
// and to multiply them to get the answers
// https://www.youtube.com/watch?v=bNvIQI2wAjk&t=321s
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Create a vector to store the answers
        vector<int> ans(n);

        // set left as 1 because the first value in the array has no prefixes. So set a default value as 1.
        int left = 1;
        for(int i=0; i<n; ++i)
        {
            // Starting from the beginning of the nums array, calculate the prefixes of all indexes and store them in the answer array
            ans[i] = left;
            left *= nums[i];
        }

        // Also set the right as 1 because the last element in the array doesn't have suffixes.
        int right = 1;
        for(int i=n-1; i>=0; i--)
        {
            // Starting from the back of the nums array, now calculate the suffixes and multiply them with the prefixes 
            // and add them into the answer array in situ
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
