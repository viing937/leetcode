class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def deco(s):
            if len(s) == 1 and 1 <= int(s) <= 9:
                return 1
            elif len(s) == 2 and 10 <= int(s) <= 26:
                return 1
            else:
                return 0
        if len(s) == 0:
            return 0
        elif len(s) == 1:
            return deco(s[0])
        dp = [0] * (len(s))
        dp[0] = deco(s[0])
        dp[1] = dp[0]*deco(s[1]) + deco(s[:2])
        for i in range(2, len(s)):
            dp[i] = dp[i-1]*deco(s[i]) + dp[i-2]*deco(s[i-1:i+1])
        return dp[-1]
