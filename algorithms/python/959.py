class Solution:
    def upscale(self, grid):
        m, n = len(grid), len(grid[0])
        upscaled = [[0,0,0]*n for _ in range(m*3)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '/':
                    upscaled[i*3+0][j*3+2] = 1
                    upscaled[i*3+1][j*3+1] = 1
                    upscaled[i*3+2][j*3+0] = 1
                elif grid[i][j] == '\\':
                    upscaled[i*3+0][j*3+0] = 1
                    upscaled[i*3+1][j*3+1] = 1
                    upscaled[i*3+2][j*3+2] = 1
        return upscaled

    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        upscaled = self.upscale(grid)
        m, n = len(upscaled), len(upscaled[0])
        def dfs(x, y):
            upscaled[x][y] = 1
            if x-1 >= 0 and not upscaled[x-1][y]:
                dfs(x-1, y)
            if x+1 < m and not upscaled[x+1][y]:
                dfs(x+1, y)
            if y-1 >= 0 and not upscaled[x][y-1]:
                dfs(x, y-1)
            if y+1 < n and not upscaled[x][y+1]:
                dfs(x, y+1)

        rls = 0
        for i in range(m):
            for j in range(n):
                if not upscaled[i][j]:
                    rls += 1
                    dfs(i, j)
        return rls
