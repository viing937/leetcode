class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1 if x >= 0 else -1
        x = abs(x)
        x = sign * int(str(x)[::-1])
        if x < -2**31 or x >= 2**31:
            return 0
        else:
            return x
