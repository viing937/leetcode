class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) == 0 or len(grid[0]) == 0: return 0
        m, n = len(grid), len(grid[0])

        visitable = lambda x, y: grid[x][y] == '1'
        def dfs(x, y):
            grid[x][y] = '0'
            if x-1 >= 0 and visitable(x-1, y):
                dfs(x-1, y)
            if x+1 < m and visitable(x+1, y):
                dfs(x+1, y)
            if y-1 >= 0 and visitable(x, y-1):
                dfs(x, y-1)
            if y+1 < n and visitable(x, y+1):
                dfs(x, y+1)

        res = 0
        for i in range(m):
            for j in range(n):
                if visitable(i, j):
                    res += 1
                    dfs(i, j)
        return res
