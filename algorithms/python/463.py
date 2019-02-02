class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not len(grid):
            return 0
        m, n = len(grid), len(grid[0])
        rls = 0
        for i in range(m):
            for j in range(n):
                if not grid[i][j]:
                    continue
                if i == 0 or not grid[i-1][j]:
                    rls += 1
                if j == 0 or not grid[i][j-1]:
                    rls += 1
                if i == m-1 or not grid[i+1][j]:
                    rls += 1
                if j == n-1 or not grid[i][j+1]:
                    rls += 1
        return rls
