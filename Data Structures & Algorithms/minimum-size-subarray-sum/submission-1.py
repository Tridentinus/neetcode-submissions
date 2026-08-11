class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        

        n = len(nums)
        res = float("inf")
        L = 0
        cSum = 0
        for R in range(n):
            cSum += nums[R]
            while cSum >= target:
                res = min(res,R-L+1)

                cSum -= nums[L]
                L+=1
        
        return 0 if res == float("inf") else res
            