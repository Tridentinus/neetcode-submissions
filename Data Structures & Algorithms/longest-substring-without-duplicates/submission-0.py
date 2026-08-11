class Solution:
    from collections import defaultdict
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        wDict = defaultdict(int)
        L = 0
        res = 0

        for R in range(len(s)):
            Rval = s[R]

            while wDict[Rval] >0:
                wDict[s[L]] -=1
                L+=1
            
            wDict[Rval] =1
            res = max(res,R-L+1)

        return res
