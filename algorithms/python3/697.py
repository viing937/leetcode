class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first, last = {}, {}
        count = {}
        for idx, num in enumerate(nums):
            if num in first:
                count[num] += 1
            else:
                count[num] = 1
                first[num] = idx
            last[num] = idx
        maxF = max(count.values())
        k = list(filter(lambda x: count[x]==maxF, count.keys()))
        k.sort(key = lambda x: last[x]-first[x])
        return last[k[0]] - first[k[0]] + 1
