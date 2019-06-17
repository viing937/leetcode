from collections import Counter
class Solution(object):
    def largestOverlap(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: int
        """
        m, n = len(A), len(A[0])
        a1 = [(r, c) for r in range(m) for c in range(n) if A[r][c] == 1]
        b1 = [(r, c) for r in range(m) for c in range(n) if B[r][c] == 1]
        rls = max(Counter((ra-rb, ca-cb) for ra, ca in a1 for rb, cb in b1).values() or [0])
        return rls