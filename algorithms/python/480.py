from bisect import bisect_left, insort
class Solution:
    def median(self, nums, k):
        return (nums[k//2] + nums[k//2-(1-k%2)]) / 2

    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        window, rls = sorted(nums[:k]), []
        for i, n in enumerate(nums[k:], k):
            rls.append(self.median(window, k))
            window.pop(bisect_left(window, nums[i-k]))
            insort(window, n)
        rls.append(self.median(window, k))
        return rls
