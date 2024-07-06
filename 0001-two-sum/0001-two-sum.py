class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        # map = {}
        # for i in range(len(nums)):
        #     if nums[i] not in map:
        #         map[nums[i]] = []
        #     map[nums[i]].append(i)

        # nums.sort()
        # left, right = 0, len(nums) - 1
        # res = []
        
        # while right > left:
        #     if nums[left] + nums[right] == target:
        #         if nums[left] == nums[right]:
        #             for i in map[nums[left]]:
        #                 res.append(i)
        #             return res
        #         else:
        #             res.append(map[nums[left]][0])
        #             res.append(map[nums[right]][0])
        #             return res
        #     elif nums[left] + nums[right] > target:
        #         right -= 1
        #         continue
        #     else:
        #         left += 1
        test = {}
        
        for i in range(len(nums)):
            if nums[i] in test:
                return [i, test[nums[i]]]
            else:
                test[target-nums[i]] = i
        