class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        queue = deque() # store the indices
        l = r = 0

        while r < len(nums):
            # pop smaller values from the queue
            while queue and nums[queue[-1]] < nums[r]:
                queue.pop()
            queue.append(r)

            # remove left value from window when left pointer is at the boundary
            if l > queue[0]:
                queue.popleft()
            
            # check if the size of the window is at least the size of k
            if (r+1) >= k:
                res.append(nums[queue[0]])
                l += 1

            r += 1
        return res