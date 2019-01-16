from functools import lru_cache

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        @lru_cache(maxsize = None)
        def helper(n):
            if n == 1:
                return 1
            elif n == 2:
                return 2
            else:
                return helper(n-2) + helper(n-1)

        return helper(n)
