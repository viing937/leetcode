class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == '':
            return ''

        n = len(s)
        res = s[0]

        for i in range(n):
            l, r = i, i
            while l-1 >= 0 and r+1 < n and s[l-1]==s[r+1]:
                l -= 1
                r += 1
            if r-l+1 > len(res):
                res = s[l:r+1]

        for i in range(n-1):
            if s[i] != s[i+1]:
                continue
            l, r = i, i+1
            while l-1 >= 0 and r+1 < n and s[l-1]==s[r+1]:
                l -= 1
                r += 1
            if r-l+1 > len(res):
                res = s[l:r+1]

        return res
