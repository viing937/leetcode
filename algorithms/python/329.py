class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not len(matrix) or not len(matrix[0]):
            return 0

        m, n = len(matrix), len(matrix[0])
        pq = sorted([(matrix[i][j], i, j) for i in range(m) for j in range(n)])

        rls = [[1 for i in range(n)] for j in range(m)]
        for v, x, y in pq:
            if x-1 >= 0 and matrix[x-1][y] > v:
                rls[x-1][y] = max(rls[x-1][y], rls[x][y]+1)
            if x+1 < m and matrix[x+1][y] > v:
                rls[x+1][y] = max(rls[x+1][y], rls[x][y]+1)
            if y-1 >= 0 and matrix[x][y-1] > v:
                rls[x][y-1] = max(rls[x][y-1], rls[x][y]+1)
            if y+1 < n and matrix[x][y+1] > v:
                rls[x][y+1] = max(rls[x][y+1], rls[x][y]+1)

        return max(map(max, rls))
