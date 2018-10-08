class Solution(object):
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        target = abs(target)
        n = int((target * 2) ** 0.5)
        steps = n * (n+1) // 2
        while steps < target or (steps - target) % 2:
            n += 1
            steps += n
        return n
