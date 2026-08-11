class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)

        res = 0
        for n in numSet:
            if (n-1) not in numSet:
                print("Found Tail: ", n)
                l=1
                #traverse up tail
                while(n+l) in numSet:
                    l+=1
                res = max(res,l)
        return res