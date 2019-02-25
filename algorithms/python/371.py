from ctypes import c_int32, c_uint32

class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        s, c = a^b, a&b
        while c:
            a, b = s, c_uint32(c<<1).value
            s, c = a^b, a&b
        return c_int32(s).value
