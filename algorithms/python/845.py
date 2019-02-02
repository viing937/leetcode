class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        rls = 0
        for i in range(1, len(A)-1):
            if A[i-1] < A[i] and A[i] > A[i+1]:
                l, r = i-1, i+1
                while l-1 >= 0 and A[l-1] < A[l]:
                    l -= 1
                while r+1 < len(A) and A[r+1] < A[r]:
                    r += 1
                rls = max(rls, r-l+1)
        return rls
