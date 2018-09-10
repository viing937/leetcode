from itertools import product

class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        l = len(nums)
        if l <= 1:
            return [nums]
        pers = self.permute(nums[:l-1])
        r = []
        for p in product(pers, range(l)):
            r.append(p[0][:])
            r[-1].insert(p[1], nums[-1])
        return r
