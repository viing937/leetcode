from functools import reduce
from functools import lru_cache


class Solution(object):
    def minScoreTriangulation(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

        @lru_cache(maxsize=None)
        def helper(left, right):
            if right - left < 2:
                return 0
            score = A[left] * A[right]
            rls = 0x7FFFFFFF
            for i in range(left + 1, right):
                rls = min(rls, helper(left, i) + helper(i, right) + score * A[i])
            return rls

        return helper(0, len(A) - 1)
