class Solution:
    def findMin(self, nums: List[int]) -> int:
        

        # res = nums[0]
        # l, r = 0, len(nums) - 1

        # while l <= r:
        #     if nums[l] < nums[r]:
        #         res = min(res, nums[l])
        #         break

        #     m = (l + r) // 2
        #     res = min(res, nums[m])
        #     if nums[m] >= nums[l]:
        #         l = m + 1
        #     else:
        #         r = m - 1
        # return res
        res = nums[0]

        L, R = 0, len(nums)-1

        while L <= R:
            # if left < right we are in a fully sorted portion\
            if nums[L] <= nums[R]:
                res = min(res,nums[L]) # update with smallest (leftmost) val
                break
            
            # otherwise we continue
            m = (L+R)//2
            # check if we landed our midpoint on min 
            res = min(res,nums[m])

            # check if midpoint in left region
            if nums[m] >= nums[L]:
                #we explore the right
                L = m + 1
            # if in the right region, narrow the sorted area
            else:
                # not this skips the min if at mid point 
                # resolved in line
                R = m - 1
        return res
            


