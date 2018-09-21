from collections import defaultdict

class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        dist = defaultdict(lambda: defaultdict(int))
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                x, y = points[i], points[j]
                d = self.calDist(x, y)
                dist[i][d] += 1
                dist[j][d] += 1
        rls = 0
        for i in dist:
            for k, v in dist[i].items():
                rls += v * (v-1)
        return rls

    def calDist(self, x, y):
        return (x[0]-y[0])**2 + (x[1]-y[1])**2
