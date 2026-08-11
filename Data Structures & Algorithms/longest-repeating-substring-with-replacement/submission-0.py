class Solution:
    from collections import defaultdict
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        counts = defaultdict(int)
        L,res = 0,0

        for R in range(n):
            counts[s[R]] +=1
            while sum(counts.values()) - max(counts.values()) > k:
                counts[s[L]] -=1
                L+=1
            res = max(res,R-L+1)

        return res