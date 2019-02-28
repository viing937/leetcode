class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n = ('0'*32+bin(n)[2:])[-32:]
        return int(n[::-1], 2)
