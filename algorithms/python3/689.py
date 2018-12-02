from itertools import accumulate
class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n, m = len(nums), 3
        acc = [0] + list(accumulate(nums))
        getSum = lambda x: acc[x+k] - acc[x]

        dp = [[0]*(n+1) for _ in range(m+1)]
        path = [[0]*(n+1) for _ in range(m+1)]

        for i in range(1, 4):
            for j in range(k, n+1):
                include = getSum(j-k) + dp[i-1][j-k]
                exclude = dp[i][j - 1]
                if include > exclude:
                    dp[i][j] = include
                    path[i][j] = j - k
                else:
                    dp[i][j] = exclude
                    path[i][j] = path[i][j-1]

        res = [0] * 3
        res[2] = path[3][-1]
        res[1] = path[2][res[2]]
        res[0] = path[1][res[1]]
        return res
