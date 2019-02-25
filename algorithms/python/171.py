class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        s, base = s[::-1], 1
        rls = 0
        for ch in s:
            rls += (ord(ch)-ord('A')+1) * base
            base *= 26
        return rls
