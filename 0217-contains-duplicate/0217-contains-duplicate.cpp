class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> pSet;

        for(int i=0; i<nums.size(); ++i)
        {
            if(pSet.count(nums[i]) >= 1)
            {
                return true;
            }
            pSet.insert(nums[i]);
        }

        return false;
        
    }
};