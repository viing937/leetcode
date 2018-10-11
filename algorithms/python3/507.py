class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 1:
            return False
        s, t = 1, int(num ** 0.5)
        for i in range(2, t+1):
            if num % i == 0:
                s += i + num//i
        if t * t == num:
            s -= t
        return s == num
