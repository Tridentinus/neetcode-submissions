class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        preProd = 1
        pre = []
        for n in nums:
            preProd*=n
            pre.append(preProd)

        postProd = 1
        post = []
        for n in reversed(nums):
            postProd*=n
            post.insert(0,postProd)
        
        res = []
        for i in range(len(nums)):
            prev = 1 if i == 0 else pre[i-1]
            nxt = 1 if i ==len(nums)-1 else post[i+1]

            res.append(prev*nxt)
        return res