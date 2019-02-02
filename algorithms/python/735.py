class Solution:
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        res = []
        for aster in asteroids:
            res.append(aster)
            while len(res) >= 2 and res[-2] > 0 and res[-1] < 0:
                a = res.pop()
                b = res.pop()
                if abs(a) > abs(b):
                    res.append(a)
                elif abs(a) < abs(b):
                    res.append(b)
        return res
