class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        operators = set(["+","-","*","/"])
        operands = []

        for s in tokens:
            if s in operators:
                op2,op1 = operands.pop(), operands.pop()
                match s:
                    case "+": res = op1 + op2
                    case "-": res = op1 - op2
                    case "*": res = op1 * op2
                    case "/": res = op1 / op2

                operands.append(int(res))
            else:
                operands.append(int(s))

        return operands.pop()
