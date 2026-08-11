class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        

        maxA = 0
        stack = []
        
        # for each bar
        for i,h in enumerate(heights):

            # starts at itself by default
            start = i
            
            #for every previous bar larger
            while stack and stack[-1][1] > h:
                # could have start at the larger bar
                start, oldH = stack.pop()
                # finish accumulating larger bar area
                maxA = max(maxA, oldH * (i-start))
            # add height to stack with possibly farther left start
            stack.append((start,h))
        # check all unclosed areas
        for i,h in stack:
            maxA = max(maxA,  h * (len(heights)-i))

        return maxA