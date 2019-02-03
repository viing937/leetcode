from functools import lru_cache
class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        @lru_cache(maxsize=None)
        def helper(n):
            if n == 0 or n == 1:
                return 0
            else:
                return min(helper(n-2)+cost[n-2], helper(n-1)+cost[n-1])
        return helper(len(cost))
