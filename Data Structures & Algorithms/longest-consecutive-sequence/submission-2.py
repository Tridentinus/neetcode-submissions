class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        numSet = set(nums)

        ans = 0

        for n in numSet:
            if (n-1) not in numSet:
                length = 1
                while (n + length) in numSet:
                    length +=1
                ans = max(length,ans)

        return ans
