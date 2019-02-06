class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        """
        :type A: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        s = sum([n for n in A if not n%2])
        rls = [0] * len(queries)
        for i, q in enumerate(queries):
            val, idx = q
            if not A[idx]%2:
                s -= A[idx]
            A[idx] += val
            if not A[idx]%2:
                s += A[idx]
            rls[i] = s
        return rls
