class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isPrime = [1] * n
        isPrime[:2] = [0, 0]
        for i in range(2, n):
            if isPrime[i]:
                for j in range(2*i, n, i):
                    isPrime[j] = 0
        return sum(isPrime)
