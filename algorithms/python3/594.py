from collections import Counter
class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c = Counter(nums)
        rls = 0
        for num in c:
            if num+1 in c:
                rls = max(rls, c[num] + c[num+1])
        return rls
