class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                board[i][j] += self.count(board, i, j) << 1
        for i in range(m):
            for j in range(n):
                cnt = board[i][j] >> 1
                if cnt < 2 or cnt > 3:
                    board[i][j] = 0
                elif cnt == 2:
                    board[i][j] = board[i][j] & 1
                elif cnt == 3:
                    board[i][j] = 1

    def count(self, board, x, y):
        m, n = len(board), len(board[0])
        cnt = 0
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if i >= 0 and i < m and j >= 0 and j < n:
                    cnt += board[i][j] & 1
        cnt -= board[x][y] & 1
        return cnt
