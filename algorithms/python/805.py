import sys
class Solution:
    def splitArraySameAverage(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        l = len(A)
        dp = [set() for i in range(l+1)]
        dp[0].add(0)
        for i in range(1, l+1):
            for j in range(i, 0, -1):
                for t in dp[j-1]:
                    dp[j].add(t+A[i-1])
        avg = sum(A) / l
        for i in range(1, l):
            t = round(avg * i)
            if abs(t - avg * i) < sys.float_info.epsilon and t in dp[i]:
                return True
        return False
