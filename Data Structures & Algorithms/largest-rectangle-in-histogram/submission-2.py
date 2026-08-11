class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        

        maxA = 0
        stack = []
        for i,h in enumerate(heights):
            newIdx = i
            while stack and stack[-1][1] > h:
                newIdx, hght = stack.pop()
                maxA = max(maxA, hght * (i-newIdx))
            stack.append((newIdx,h))

        for i,h in stack:
            maxA = max(maxA,  h * (len(heights)-i))

        return maxA