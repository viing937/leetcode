class Solution:
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if len(num) == 0:
            return []
        num = list(map(int, num))
        self.rls = []
        self.dfs(num, target, 1, str(num[0]), 0, num[0], num[0])
        return self.rls

    def dfs(self, num, target, i, expr, s, p, cur):
        if i == len(num):
            if s + p == target:
                self.rls.append(expr)
        else:
            self.dfs(num, target, i+1, expr+'+'+str(num[i]), s+p, +num[i], num[i])
            self.dfs(num, target, i+1, expr+'-'+str(num[i]), s+p, -num[i], num[i])
            self.dfs(num, target, i+1, expr+'*'+str(num[i]), s, p*num[i], num[i])
            if cur:
                self.dfs(num, target, i+1, expr+str(num[i]), s, p*10+p//cur*num[i], cur*10+num[i])
