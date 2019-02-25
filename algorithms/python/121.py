class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices: return 0
        minP = prices[0]
        rls = 0
        for i, n in enumerate(prices):
            rls = max(rls, n-minP)
            minP = min(minP, n)
        return rls
