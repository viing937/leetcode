class Solution:
    def countPalindromicSubsequences(self, S):
        """
        :type S: str
        :rtype: int
        """
        l = len(S)

        m = [[-1] * 4 for i in range(l)]
        for i in range(l):
            ch = ord(S[i])-ord('a')
            for j in range(i, l):
                m[j][ch] = i

        dp = [[0]*l for i in range(l)]
        for right in range(l):
            for left in range(right, -1, -1):
                if left == right:
                    dp[left][right] = 1
                elif S[left] != S[right]:
                    dp[left][right] = dp[left+1][right]
                else:
                    dp[left][right] = 2 + self.count(left+1, right-1, dp, m)
        return self.count(0, l-1, dp, m)

    def count(self, left, right, dp, m):
        c = 0
        for i in range(4):
            if m[right][i] >= left:
                c += dp[left][m[right][i]]
                c %= 1000000007
        return c
