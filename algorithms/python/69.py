class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        p, q = 1, x
        while abs(p-q) > 0.001:
            p = (p+q) / 2
            q = x / p
        return int((p+q)/2)
