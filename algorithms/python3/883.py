class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        xy = sum(map(lambda x: len(x)-x.count(0), grid))
        xz = sum(map(max, grid))
        yz = sum(map(max, zip(*grid)))
        return xy + xz + yz
