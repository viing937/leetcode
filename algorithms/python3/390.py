class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        first, sep = 1, 1
        step = 0
        while n > 1:
            step += 1
            if step % 2 or n % 2:
                first = first + sep
                sep *= 2
                n //= 2
            else:
                first = first
                sep *= 2
                n //= 2
        return first
