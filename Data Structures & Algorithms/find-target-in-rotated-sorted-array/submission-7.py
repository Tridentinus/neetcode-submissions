class Solution:
    def search(self, nums: List[int], target: int) -> int:
        

        L, R = 0 , len(nums)-1


        while L <= R:
            m = (L + R)//2
            if target == nums[m]:
                return m
            # if mid in left portion (greater)
            if nums[L] <= nums[m]:
                if target > nums[m] or target < nums[L]:
                    # if
                    # (a) target is greater than mid so look for greater part of left
                    # (b) target less than entire left portion so look for right
                    L = m +1
                else:
                    # look lower in left
                    R = m -1
                    
            else: 
            # if mid in right portion (lesser)
                if target < nums[m] or target > nums[R]:
                    # if
                    # (a) target less than mid so look for lesser part of right
                    # (b) target greater than entire right portion so look for left
                    R = m -1
                else:
                    L = m +1
                
        return -1
