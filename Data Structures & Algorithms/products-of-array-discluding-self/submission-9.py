class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        preProd = []
        postProd = []
        res = []

        prod = 1
        for n in nums:
            prod *= n
            preProd.append(prod)
        
        prod = 1
        for n in nums[::-1]:
            prod *= n
            postProd.insert(0,prod)

        for i in range(len(nums)):
            if i == 0:
                pre = 1
                post = postProd[i+1]
            elif i == len(nums)-1:
                post = 1       
                pre = preProd[i-1]
            else:
                pre = preProd[i-1]
                post = postProd[i+1]
            
            res.append(pre * post)
        return res
        
