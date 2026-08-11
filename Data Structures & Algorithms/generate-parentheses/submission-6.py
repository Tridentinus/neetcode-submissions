class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # we start with no opening or closing added

        numO = 0 
        numC = 0

        # array of valid strings found
        res = []

        # stack for current hypothetical 
        # we can try (push) and undo (pop) with
        hypothetical = []
        def explore(numO,numC):

            # BASE CASE: string is fully formed
            if numO == numC == n:
                # add this string to results and dont continue
                res.append("".join(hypothetical))
            
            # CAN WE ADD AN OPENER?
            if numO < n:
                # add an opener 
                hypothetical.append("(")
                # recursively explore all subcases
                explore(numO+1,numC)
                # return to previous state
                hypothetical.pop()
            
            # CAN WE ADD A CLOSER?
            if numC < numO:
                # add a closer
                hypothetical.append(")")
                # recursively explore all subcases
                explore(numO,numC+1)
                # return to previous state
                hypothetical.pop()
        
        explore(0,0)
        return res

