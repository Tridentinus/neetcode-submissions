class Solution:
    def isValid(self, s: str) -> bool:
        # set of openers/closers
        pres = set(["(","{","["])
        posts = set([")","}","]"])
        # valid pairs
        matches = set([("{","}"),("(",")"),("[","]")])
       

        stack = []

        for char in s:
            #if opener add to stack
            if char in pres:
                stack.append(char)
            elif char in posts:
                # if unmatched close fail
                if len(stack) == 0:
                    return False
                pair = (stack.pop(),char)
                # if match isnt valid fail
                if not pair in matches:
                    return False
        # if any unclosed openers remain fail
        return len(stack) == 0