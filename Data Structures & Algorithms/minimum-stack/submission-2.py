class MinStack:

    def __init__(self):
        self.stack = []
        self.minval = float("inf")

    def push(self, val: int) -> None:
        self.stack.append([val,self.minval])
        self.minval = min(val,self.minval)

    def pop(self) -> None:
        popped = self.stack.pop()
        self.minval = popped[1]

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.minval
        