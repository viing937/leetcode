class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        n = len(nums)
        dp, cnt = [1]*n, [1]*n
        for i in range(n):
            for j in range(i+1, n):
                if nums[i] >= nums[j]:
                    continue
                if dp[i]+1 > dp[j]:
                    dp[j] = dp[i]+1
                    cnt[j] = cnt[i]
                elif dp[i]+1 == dp[j]:
                    cnt[j] += cnt[i]
        maxLen = max(dp)
        rls = sum(map(lambda x: cnt[x[0]] if dp[x[0]] == maxLen else 0, enumerate(dp)))
        return rls