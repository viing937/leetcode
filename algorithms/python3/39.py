class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        dp = [set() for i in range(target+1)]
        dp[0].add(())
        for item in candidates:
            for i in range(target+1):
                j = 1
                while i + j * item <= target:
                    k = i + j * item
                    dp[k].update(set(map(lambda x: x + (item, ) * j, dp[i])))
                    j += 1
        return list(dp[target])
