class Solution:
    from collections import defaultdict
    def characterReplacement(self, s: str, k: int) -> int:
        # init useful structs
        n = len(s)
        counts = defaultdict(int)
        L,res = 0,0

        # advance right pointer
        for R in range(n):
            counts[s[R]] +=1
            # while failing condition
            while sum(counts.values()) - max(counts.values()) > k:
                # advance left pointer
                counts[s[L]] -=1
                L+=1
            # update max valid
            res = max(res,R-L+1)

        return res