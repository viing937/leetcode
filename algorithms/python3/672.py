class Solution:
    def flipLights(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if m == 0:
            return 1
        elif n == 1:
            return 2
        elif n == 2:
            if m == 1:
                return 3
            else:
                return 4
        else:
            if m == 1:
                return 4
            elif m == 2:
                return 7
            else:
                return 8
