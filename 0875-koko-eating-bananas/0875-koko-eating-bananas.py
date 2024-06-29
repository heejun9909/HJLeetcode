class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if h == len(piles):
            return max(piles)
        
        res = max(piles)

        start, end = 1, res
                
        while end >= start:
            mid = (end - start) // 2 + start

            calc = 0
            for i in range(len(piles)):
                calc += math.ceil(piles[i] / mid)

            if calc <= h:
                end = mid - 1
                if mid < res:
                    res = mid
            else:
                start = mid + 1
        
        return res
            
        