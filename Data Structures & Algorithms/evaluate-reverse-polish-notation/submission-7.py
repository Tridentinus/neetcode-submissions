class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = set(["+","-","*","/"])
        stack = []
        for t in tokens:
            if t not in operators:
                stack.append(t)
                continue
            a = int(stack.pop())
            b = int(stack.pop())
            if t == "+":
                stack.append(b+a)
                continue
            if t == "-":
                stack.append(b-a)
                continue
            if t == "*":
                stack.append(b*a)
                continue
            if t == "/":
                stack.append(b/a)
                continue
        return int(stack[-1])