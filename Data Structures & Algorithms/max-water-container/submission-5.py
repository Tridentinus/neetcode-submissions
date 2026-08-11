class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        L, R = 0, len(heights)-1
        
        res = 0

        while L < R:
            # update the result with the area (height of lowest bar)
            res = max(min(heights[L],heights[R]) * abs(R-L),res)

            # progress from lower bar inwards
            
            #if the right bar is higher move the left bar inwards
            if heights[R]>=heights[L]:
                L+=1
            # vice versa
            else:
                R-=1
            
        return res