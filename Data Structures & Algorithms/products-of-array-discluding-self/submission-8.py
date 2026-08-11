class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        pre  = [1] * len(nums)
        post = [1] * len(nums)
        pre[0] = nums[0]
        for i in range(1,len(nums)):
            pre[i] = pre[i-1] * nums[i]

        post[len(nums)-1] = nums[len(nums)-1]

        for j in range(len(nums)-2,-1,-1):
            post[j] = post[j+1] * nums[j]

        out = [1]*len(nums)
        for k in range(len(nums)):
            if k == 0:
                out[k] = post[k+1]
            elif k == len(nums)-1:
                out[k] = pre[k-1]
            else:
                out[k] = pre[k-1] * post[k+1]
        print(pre,post)
        return out

        


        
