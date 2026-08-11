class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
         
        
        res = set()

        nums.sort() # performed in O(nlogn) time < target O(n2)


        # perform the O(n) 2sum n times
        for i, val in enumerate(nums):
            
            target =-val # perform 2sum(target=-val) 
            
            # start on remaining entries
            L = i+1 
            R = len(nums)-1 
            
            while L < R:
                twosum = nums[L] + nums[R]
                
                #for valid solve don't break loop (modified)
                if twosum == target:
                    res.add((val,nums[L],nums[R]))
                    # arbitrary pointer advance 
                    R-=1
                if twosum < target:
                    L+=1
                if twosum > target:
                    R-=1                
                
        return list(res)
