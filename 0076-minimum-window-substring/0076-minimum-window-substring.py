class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "": return ""

        win, target = {}, {}

        for n in t:
            target[n] = 1 + target.get(n, 0)    # get the value of n if n exists in the map(target) or give default value (0)
        
        have, need = 0, len(target) 
        left, right = 0, 0
        res, reslen = "", float("inf")

        for right in range(len(s)):
            char = s[right]
            if char in target:
                win[char] = 1 + win.get(char, 0)
            
                if win[char] == target[char]:
                    have += 1

            while have == need:
                # update our result
                if right - left + 1 < reslen:
                    res = s[left:right+1]
                    reslen = right - left + 1

                # pop from the left of our window
                if s[left] in target:
                    win[s[left]] -= 1
                    # update the have variable
                    if win[s[left]] < target[s[left]]:
                        have -= 1

                left += 1
        return res