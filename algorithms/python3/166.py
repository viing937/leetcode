class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        sign = '-' if numerator * denominator < 0 else ''
        numerator, denominator = abs(numerator), abs(denominator)
        rls = [str(numerator // denominator), '.']
        numerator %= denominator
        if numerator == 0:
            return sign + rls[0]
        m = {numerator: len(rls)}
        while numerator:
            numerator *= 10
            rls.append(str(numerator // denominator))
            numerator %= denominator
            if numerator in m:
                return sign + ''.join(rls[:m[numerator]]) + '(' + ''.join(rls[m[numerator]:]) + ')'
            m[numerator] = len(rls)
        return sign + ''.join(rls)
