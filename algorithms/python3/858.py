import math

class Solution:
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        d = p * q // math.gcd(p, q)
        s = p * d // q
        d, s = d // p, s // p
        if d % 2:
            return 1 if s % 2 else 2
        else:
            return 0 if s % 2 else 1
