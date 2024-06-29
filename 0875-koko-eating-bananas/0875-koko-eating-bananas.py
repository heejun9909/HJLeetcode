class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        if h == len(piles):
            return piles[-1]
        
        res = piles[-1]

        start, end = 1, piles[-1]
                
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
            
        