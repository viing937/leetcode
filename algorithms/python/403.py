class Solution:
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        if stones[1] - stones[0] != 1:
            return False
        m = {stones[1]: set([1])}
        for i in range(1, len(stones)):
            stone = stones[i]
            if stone not in m:
                continue
            for step in m[stone]:
                for nextS in [step-1, step, step+1]:
                    if nextS <= 0:
                        continue
                    if stone + nextS not in m:
                        m[stone + nextS] = set()
                    m[stone + nextS].add(nextS)
        return stones[-1] in m
