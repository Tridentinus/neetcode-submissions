class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        

        sums = []
        res = 0
        compDict = {}

        pre = 0
        for n in nums:
            pre += n
            sums.append(pre)
        

        for s in sums[::-1]:
            if s == k:
                res+=1
            c = s-k

            res += compDict.get(s,0)
            compDict[c] = compDict.get(c,0) + 1

        return res