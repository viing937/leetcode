from collections import Counter
class Solution:
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        c = Counter(nums)
        k = sorted(c.keys())
        dp = [0] * (len(k)+1)
        dp[1] = k[0] * c[k[0]]
        for i in range(1, len(k)):
            if k[i] == k[i-1] + 1:
                dp[i+1] = max(dp[i], dp[i-1] + k[i] * c[k[i]])
            else:
                dp[i+1] = dp[i] + k[i] * c[k[i]]
        return dp[-1]
