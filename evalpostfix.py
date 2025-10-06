class Solution:
    def evaluatePostfix(self, arr):
        stack = []

        for token in arr:
            if token in "+-*/^":
                b = stack.pop()
                a = stack.pop()

                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    # Floor division that handles negatives correctly
                    stack.append(int(a / b))
                elif token == '^':
                    stack.append(pow(a, b))
            else:
                stack.append(int(token))

        return stack[-1]
