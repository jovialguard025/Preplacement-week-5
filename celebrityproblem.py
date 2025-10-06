class Solution:
    def celebrity(self, mat):
        n = len(mat)
        candidate = 0

        # Step 1: Find the potential celebrity
        for i in range(1, n):
            if mat[candidate][i] == 1:
                # candidate knows i → candidate can't be celebrity
                candidate = i

        # Step 2: Verify the candidate
        for i in range(n):
            if i != candidate:
                if mat[candidate][i] == 1 or mat[i][candidate] == 0:
                    return -1

        return candidate