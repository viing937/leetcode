from itertools import product
class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1:
            return self.count(s)
        mod, m = 10**9+7, self.buildMap()
        dp = [0] * len(s)
        dp[0] = m[s[0:1]]
        dp[1] = m[s[0:2]] + dp[0] * m[s[1:2]]
        for i in range(2, len(s)):
            dp[i] = dp[i-2] * m[s[i-1:i+1]]
            dp[i] %= 10**9+7
            dp[i] += dp[i-1] * m[s[i:i+1]]
            dp[i] %= 10**9+7
        return dp[-1]

    def buildMap(self):
        charset = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*']
        m = {}
        for ch in charset:
            m[ch] = self.count(ch)
        for p in product(charset, charset):
            ch = p[0]+p[1]
            m[ch] = self.count(ch)
        return m

    def count(self, s):
        if len(s) == 1:
            if s[0] == '*':
                return 9
            elif s[0] == '0':
                return 0
            else:
                return 1
        if len(s) == 2:
            if s == '**':
                return 15
            elif s[0] == '*':
                return 2 if s[1] <= '6' else 1
            elif s[0] == '0':
                return 0
            elif s[1] == '*' and s[0] == '1':
                return 9
            elif s[1] == '*' and s[0] == '2':
                return 6
            elif s[1] == '*':
                return 0
            elif int(s) <= 26:
                return 1
            else:
                return 0
