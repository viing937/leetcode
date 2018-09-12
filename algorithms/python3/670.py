class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = list(str(num))
        for i in range(len(s)):
            for j in range(i):
                t = s[:]
                t[i], t[j] = t[j], t[i]
                num = max(num, int(''.join(t)))
        return num
