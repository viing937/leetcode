class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        b = bin(n)[2:]
        odd = list(set(b[::2]))
        even = list(set(b[1::2]))
        if len(odd) == 0 or len(even) == 0: return True
        return len(odd) == 1 and len(even) == 1 and odd[0] != even[0]
