class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return
        m, n = len(board), len(board[0])
        visited = [[False] * n for i in range(m)]
        f = lambda x, y: board[x][y] == 'O' and not visited[x][y]
        for i in range(m):
            if f(i, 0):
                self.helper(i, 0, board, visited)
            if f(i, n-1):
                self.helper(i, n-1, board, visited)
        for i in range(n):
            if f(0, i):
                self.helper(0, i, board, visited)
            if f(m-1, i):
                self.helper(m-1, i, board, visited)
        for i in range(m):
            for j in range(n):
                if f(i, j):
                    board[i][j] = 'X'

    def helper(self, i, j, board, visited):
        m, n = len(board), len(board[0])
        visited[i][j] = True
        f = lambda x, y: board[x][y] == 'O' and not visited[x][y]
        if i-1 >= 0 and f(i-1, j):
            self.helper(i-1, j, board, visited)
        if i+1 < m and f(i+1, j):
            self.helper(i+1, j, board, visited)
        if j-1 >= 0 and f(i, j-1):
            self.helper(i, j-1, board, visited)
        if j+1 < n and f(i, j+1):
            self.helper(i, j+1, board, visited)
