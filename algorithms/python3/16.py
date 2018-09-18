class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        rls = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            j, k = i+1, len(nums)-1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return s
                rls = s if abs(s-target) < abs(rls-target) else rls
                if s < target:
                    j += 1
                else:
                    k -= 1
        return rls
