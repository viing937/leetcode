class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt5 = 0
        base = 5
        while base <= n:
            cnt5 += n // base
            base *= 5
        return cnt5
