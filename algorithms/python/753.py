class Solution:
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        start = '0' * n
        state = list(start)
        targetLen = k ** n + n - 1
        visited = {start: True}

        def dfs(s):
            if len(state) == targetLen:
                return state
            for i in range(k):
                ch = str(i)
                ns = s[1:] + ch
                if ns not in visited or not visited[ns]:
                    visited[ns] = True
                    state.append(ch)
                    rls = dfs(ns)
                    if rls:
                        return rls
                    state.pop()
                    visited[ns] = False
            return None

        return ''.join(dfs(start))
