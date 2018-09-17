class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        rls = self.helper(num, k).lstrip('0')
        return rls if len(rls) else '0'

    def helper(self, num, k):
        if k == 0:
            return num
        for i in range(len(num)-1):
            if num[i] > num[i+1]:
                return self.helper(num[:i] + num[i+1:], k-1)
        return self.helper(num[:-1], k-1)
