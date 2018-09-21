class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        diff = [prices[i] - prices[i-1] for i in range(1, len(prices))]
        return sum(filter(lambda x: x > 0, diff))
