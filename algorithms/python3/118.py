class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0: return []
        rls = [[1]]
        for i in range(2, numRows+1):
            row = [1] * i
            for j in range(1, i-1):
                row[j] = rls[-1][j-1] + rls[-1][j]
            rls.append(row)
        return rls
