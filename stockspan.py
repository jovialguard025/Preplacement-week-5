class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        span = [0] * n
        stack = []  # stores indices

        for i in range(n):
            # Pop elements from stack while current price is higher
            while stack and arr[i] >= arr[stack[-1]]:
                stack.pop()

            # If stack is empty, all previous prices are smaller
            if not stack:
                span[i] = i + 1
            else:
                span[i] = i - stack[-1]

            stack.append(i)

        return span
