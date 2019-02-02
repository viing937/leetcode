class Solution:
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        if s == '':
            return 0

        i, sign = 0, 1
        if s[i] == '+' or s[i] == '-':
            sign = -1 if s[i] == '-' else 1
            i += 1

        rls = 0
        while i < len(s) and s[i].isdigit():
            rls = rls * 10 + int(s[i])
            i += 1

        rls = rls * sign
        rls = min(rls, +2147483647)
        rls = max(rls, -2147483648)
        return rls
