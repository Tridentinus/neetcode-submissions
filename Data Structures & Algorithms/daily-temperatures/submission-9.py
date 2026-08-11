class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # zero-initialize
        res = [0] * len(temperatures)

        stack = []

        for i,t in enumerate(temperatures):
            while len(stack) > 0 and stack[-1][0] < t:
                prevIdx = stack.pop()[1]
                print(prevIdx)
                res[prevIdx] = i - prevIdx
            
            stack.append([t,i])
        return res