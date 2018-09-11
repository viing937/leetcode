class Solution:
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0:
            num += 1 << 32
        return hex(num)[2:]
