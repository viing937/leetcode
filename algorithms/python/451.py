from functools import reduce
from collections import Counter
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        c = sorted(Counter(s).items(), key=lambda x: x[1], reverse=True)
        rls = reduce(lambda t, x: t+x[0]*x[1], c, '')
        return rls
