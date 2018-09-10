class Solution:
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        l, s = len(A), sum(A)
        if l == 0:
            return 0
        f = [0] * l
        f[0] = sum([i*A[i] for i in range(l)])
        for i in range(1, l):
            f[i] = f[i-1] + s - l * A[l-i]
        return max(f)
