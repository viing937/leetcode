class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        N, K = N-1, K-1
        def helper(N, K):
            if N == 0: return 0
            prev = helper(N-1, K//2)
            return (K+prev)%2
        return helper(N, K)
