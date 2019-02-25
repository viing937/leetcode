class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        t = list(set(nums))
        return len(t) != len(nums)
