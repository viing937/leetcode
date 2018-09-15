class Solution:
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A == B:
            return True
        for i in range(len(A)):
            t = A[i:] + A[:i]
            if t == B:
                return True
        return False
