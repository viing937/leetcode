class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        a, b = m, n
        for p in ops:
            a = min(a, p[0])
            b = min(b, p[1])
        return a * b
