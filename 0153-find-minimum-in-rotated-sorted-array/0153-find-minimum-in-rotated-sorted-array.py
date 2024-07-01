class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        res = nums[0]

        while right >= left:
            if nums[right] > nums[left]:
                res = min(res, nums[left])
                break

            mid = (left + right) // 2
            res = min(res, nums[mid])

            if nums[mid] >= nums[left]: 
                left = mid + 1
                
            else:
                right = mid - 1
            
        return res