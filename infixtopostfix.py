class Solution:
    def infixtoPostfix(self, s):
        def precedence(op):
            if op == '^':
                return 3
            elif op in ('*', '/'):
                return 2
            elif op in ('+', '-'):
                return 1
            return 0

        def is_right_associative(op):
            return op == '^'

        def is_operator(c):
            return c in '+-*/^'

        stack = []
        output = []

        for ch in s:
            if ch.isalnum():  # Operand
                output.append(ch)
            elif ch == '(':
                stack.append(ch)
            elif ch == ')':
                while stack and stack[-1] != '(':
                    output.append(stack.pop())
                if stack and stack[-1] == '(':
                    stack.pop()
            elif is_operator(ch):
                while (stack and stack[-1] != '(' and
                       (precedence(stack[-1]) > precedence(ch) or
                        (precedence(stack[-1]) == precedence(ch) and not is_right_associative(ch)))):
                    output.append(stack.pop())
                stack.append(ch)

        while stack:
            output.append(stack.pop())

        return ''.join(output)