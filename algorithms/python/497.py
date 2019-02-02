import random
from bisect import bisect
from itertools import accumulate

class Solution:
    def __init__(self, rects):
        """
        :type rects: List[List[int]]
        """
        self.rects = rects
        self.sizes = list(map(lambda x: (x[2]-x[0]+1) * (x[3]-x[1]+1), rects))
        self.weights = list(accumulate(self.sizes))

    def pick(self):
        """
        :rtype: List[int]
        """
        r = random.randrange(0, self.weights[-1])
        idx = bisect(self.weights, r)
        offset = self.sizes[idx] + r - self.weights[idx]
        width = self.rects[idx][2] - self.rects[idx][0] + 1
        return [self.rects[idx][0] + offset % width , self.rects[idx][1] + offset // width]

# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
