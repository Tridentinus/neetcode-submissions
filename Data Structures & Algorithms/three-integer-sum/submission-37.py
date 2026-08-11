class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
         
        
        res = set()

        nums.sort() # performed in O(nlogn) time < target O(n2)


        # perform the O(n) 2 sum n times
        for i, val in enumerate(nums):
            target =-val 
            L = i+1
            R = len(nums)-1
            print(val,target, nums[i+1:])
            while L < R:
                twosum = nums[L] + nums[R]
                # print("    ",nums[L],nums[R], "twosum: ", twosum)
                if twosum == target:
                    res.add((val,nums[L],nums[R]))
                    print(res)
                    L+=1
                if twosum < target:
                    L+=1
                if twosum > target:
                    R-=1                
                
        return list(res)
