class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        else:
            return (num & (num - 1)) == 0 and (num & 0x55555555) != 0

        # num & num - 1 : To check if it is powers of 2.
        # 0x55555555 : 1 bits in odd position.
