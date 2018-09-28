import math

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        k -= 1
        s = [str(i) for i in range(1, n+1)]
        rls = []
        for i in range(n-1, -1, -1):
            fac = math.factorial(i)
            idx = k // fac
            k %= fac
            rls.append(s[idx])
            s = s[:idx] + s[idx+1:]
        return ''.join(rls)
