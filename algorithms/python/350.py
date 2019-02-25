from collections import Counter
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        c1, c2 = Counter(nums1), Counter(nums2)
        r = c1 & c2
        rls = []
        for k, v in r.items():
            rls += [k] * v
        return rls
