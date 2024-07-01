class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while right >= left:
            mid = (right + left) // 2

            if nums[mid] == target:
                return mid
            
            # left sorted portion
            elif nums[mid] >= nums[left]:
                if nums[mid] < target or nums[left] > target:
                    left = mid + 1
                else:
                    right = mid - 1

            # right sorted portion
            else:
                if nums[mid] > target or nums[right] < target:
                    right = mid - 1
                else:
                    left = mid + 1

        return -1 