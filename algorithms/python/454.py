from collections import defaultdict
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        n = len(A)
        m = defaultdict(int)
        for i in range(n):
            for j in range(n):
                m[A[i]+B[j]] += 1
        rls = 0
        for i in range(n):
            for j in range(n):
                rls += m[-C[i]-D[j]]
        return rls
