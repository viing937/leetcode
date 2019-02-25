class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        sym = ['IV', 'IX', 'XL', 'XC', 'CD', 'CM', 'I', 'V', 'X', 'L', 'C', 'D', 'M']
        val = [4, 9, 40, 90, 400, 900, 1, 5, 10, 50, 100, 500, 1000]
        rls = 0
        for i in range(len(sym)):
            k, v = sym[i], val[i]
            rls += s.count(k) * v
            s = s.replace(k, '')
        return rls
