class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        

        n = len(nums)
        res = float("inf")
        L = 0
        cSum = 0
        # advance right pointer
        for R in range(n):
            # add to sum on right
            cSum += nums[R]
            # while meet condition
            while cSum >= target:
                # update min
                res = min(res,R-L+1)
                # advance left
                cSum -= nums[L]
                L+=1

        return 0 if res == float("inf") else res
            