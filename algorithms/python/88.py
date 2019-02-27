class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        i, j = m-1, n-1
        idx = m+n-1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[idx] = nums1[i]
                idx -= 1
                i -= 1
            else:
                nums1[idx] = nums2[j]
                idx -= 1
                j -= 1
        if j >= 0:
            nums1[:j+1] = nums2[:j+1]
