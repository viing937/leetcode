import functools

class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        @functools.lru_cache(maxsize=None)
        def helper(l, r):
            if l >= r:
                return 0
            return min(
                m + max(helper(l, m-1), helper(m+1, r)) for m in range(l, r+1)
            )

        return helper(1, n)
