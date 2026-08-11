class Solution:
    def isValid(self, s: str) -> bool:
        pres = set(["(","{","["])
        posts = set([")","}","]"])
        matches = set([("{","}"),("(",")"),("[","]")])
       

        stack = []

        for char in s:
            if char in pres:
                stack.append(char)
            elif char in posts:
                if len(stack) == 0:
                    return False
                pair = (stack.pop(),char)
                if not pair in matches:
                    return False
        return len(stack) == 0