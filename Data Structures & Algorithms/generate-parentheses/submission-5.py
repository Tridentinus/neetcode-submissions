class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack   = []
        res     = []

        def recursive(opens, closes):
            if opens == closes == n:
                res.append("".join(stack))
                return
            if opens < n:
                stack.append("(")
                recursive(opens+1,closes)
                stack.pop()
            if closes < opens:
                stack.append(")")
                recursive(opens,closes+1)
                stack.pop()
        recursive(0,0)
        return res

        


