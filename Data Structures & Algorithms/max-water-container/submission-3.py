class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        L, R = 0, len(heights)-1
        
        res = 0

        while L < R:
            res = max(min(heights[L],heights[R]) * abs(R-L),res)

            if heights[R]>=heights[L]:
                L+=1
            else:
                R-=1
            
        return res