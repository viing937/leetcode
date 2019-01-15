class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        def height(x, y):
            if 0 <= x < m and 0 <= y < n:
                return grid[x][y]
            else:
                return 0

        rls = 0
        for i in range(m):
            for j in range(n):
                rls += 2 if height(i, j) > 0 else 0 # top and bottom
                rls += max(0, height(i, j) - height(i-1, j))
                rls += max(0, height(i, j) - height(i+1, j))
                rls += max(0, height(i, j) - height(i, j-1))
                rls += max(0, height(i, j) - height(i, j+1))
        return rls
