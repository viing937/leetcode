class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for i in range(0, int(c**0.5)+1):
            a = i
            b = round((c - a**2) ** 0.5)
            if a**2 + b**2 == c:
                return True
        return False
