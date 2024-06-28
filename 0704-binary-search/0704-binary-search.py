class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binSearch(nums, start, end):
            if start > end:
                return -1

            mid = ((end - start) // 2) + start
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                return binSearch(nums, start, mid - 1)
            elif nums[mid] < target:
                return binSearch(nums, mid + 1, end)
        return binSearch(nums, 0, len(nums) - 1)
