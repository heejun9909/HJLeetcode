class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
            {
                break;
            }

            // Since the array is sorted as increasing order, if the sum is smaller than the target, we can move left pointer to the right to increase the sum
            else if(sum < target)
            {
                left++;
            }

            // sum is larger thant the target, so move the right pointer to the left to decrease the sum
            else
            {
                right--;
            }
        }
        return {left+1, right+1};
    }
};
