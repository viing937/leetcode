from itertools import product

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [set(['']) for i in range(n+1)]
        for i in range(1, n+1):
            dp[i] = set(['('+p+')' for p in dp[i-1]])
            for j in range(1, i):
                for l, r in product(dp[j], dp[i-j]):
                    dp[i].add(l + r)
        return list(dp[n])
