class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        x, y = click
        self.reveal(board, x, y)
        return board

    def reveal(self, board, x, y):
        m, n = len(board), len(board[0])
        if board[x][y] == 'M':
            board[x][y] = 'X'
            return
        cnt = 0
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if 0 <= i < m and 0 <= j < n:
                    cnt += 1 if board[i][j] == 'M' else 0
        if cnt != 0:
            board[x][y] = str(cnt)
            return
        board[x][y] = 'B'
        for i in range(x-1, x+2):
            for j in range(y-1, y+2):
                if 0 <= i < m and 0 <= j < n:
                    if i != x or j != y:
                        if board[i][j] == 'E':
                            self.reveal(board, i, j)
