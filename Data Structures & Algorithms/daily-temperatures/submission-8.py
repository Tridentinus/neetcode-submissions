class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        out = [0] * len(temperatures)
        stack = []

        for i,t in enumerate(temperatures):
            while stack and stack[-1][0] < t:
                stackT,stackI = stack.pop()
                out[stackI] += i - stackI
            stack.append((t,i))
        
        return out
