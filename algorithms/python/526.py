class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.count = 0
        visited = [False] * (N+1)
        self.helper(N, 1, visited)
        return self.count

    def helper(self, N, pos, visited):
        if pos == N+1:
            self.count += 1
            return
        for i in range(1, N+1):
            if visited[i]:
                continue
            if pos % i and i % pos:
                continue
            visited[i] = True
            self.helper(N, pos+1, visited)
            visited[i] = False
