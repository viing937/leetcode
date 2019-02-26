class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        m = set([n])
        while n != 1:
            n = sum(map(lambda x: int(x)**2, str(n)))
            if n in m:
                return False
            else:
                m.add(n)
        return True
