class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        one = [-1] + [i for i in range(len(A)) if A[i]==1] + [len(A)]

        rls = 0
        if S == 0:
            for i in range(1, len(one)-S):
                left = one[i] - one[i-1]
                rls += (left-1) * left // 2
        else:
            for i in range(1, len(one)-S):
                left = one[i] - one[i-1]
                right = one[i+S] - one[i+S-1]
                rls += left * right
        return rls
