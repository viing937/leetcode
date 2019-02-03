class Solution:
    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ones = [i for i in range(len(A)) if A[i]==1]

        # all zeros
        if not len(ones): return [0, 2]
        # number of ones not equal
        if len(ones)%3: return [-1, -1]

        k = len(ones) // 3
        for i in range(1, k):
            if ones[i]-ones[i-1] != ones[k+i]-ones[k+i-1]:
                return [-1, -1]
            if ones[i]-ones[i-1] != ones[2*k+i]-ones[2*k+i-1]:
                return [-1, -1]

        # number of zeros after last one
        offset = len(A) - ones[-1] - 1
        rls = [ones[k-1]+offset, ones[2*k-1]+offset+1]

        if rls[0] >= ones[k] or rls[1] > ones[2*k]:
            return [-1, -1]
        else:
            return rls
