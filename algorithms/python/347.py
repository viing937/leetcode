import heapq
from collections import Counter

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        c = Counter(nums)
        c = heapq.nlargest(k, c.items(), key=lambda x: x[1])
        rls = [e[0] for e in c]
        return rls
