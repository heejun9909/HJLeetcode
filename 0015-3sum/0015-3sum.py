class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        res = []

        for i, val in enumerate(nums):

            if i > 0 and val == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1
            
            while right > left:
                threeSum = val + nums[left] + nums[right]
                if threeSum == 0:
                    res.append([val, nums[left], nums[right]])
                    left += 1
                    while nums[left] == nums[left - 1] and left < right:
                        left += 1
                elif threeSum > 0:
                    right -= 1
                else:
                    left += 1
        
        return res