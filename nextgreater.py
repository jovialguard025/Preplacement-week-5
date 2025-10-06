class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        result = [-1] * n
        stack = []  # stores indices

        for i in range(n - 1, -1, -1):
            # Pop all elements smaller than or equal to arr[i]
            while stack and arr[stack[-1]] <= arr[i]:
                stack.pop()

            # If stack is not empty, top is the next greater
            if stack:
                result[i] = arr[stack[-1]]

            # Push current index to stack
            stack.append(i)

        return result