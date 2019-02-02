from fractions import Fraction
class Solution:
    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def toFrac(s):
            if '(' not in s:
                return Fraction(s)
            offset = s.index('(') - s.index('.') - 1
            norep, rep = s[:-1].split('(')
            norep = Fraction(norep)
            rep = Fraction(int(rep), (10**len(rep)-1) * 10**(offset))
            return norep + rep
        S, T = toFrac(S), toFrac(T)
        return S == T
